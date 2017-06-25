#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <vector>
using namespace std;

#define N 52
#define SWAP(a, b){int t; t=a; a=b; b=t;}


#define BUF_SIZE 3
//const char flower[6] = {'\5','\4','\3','\6','\1','\2'}; // 4個花色
const char number[13][BUF_SIZE] = {
    " A", " 2", " 3", " 4", " 5", " 6",
    " 7", " 8", " 9", "10", " J", " Q", " K"};


class card{
public:
    void shuttle(int *a,int b);
    void display(void);
    void selectcard(int selectwho,int num);
    void sendcard(int *poker, int Size);
    void clear(void);
    void pcselect(int selectwho);
    void judge(void);
    bool hacky(void);
private:
    int i,j,pos,j1,j2,seletwho,num;
    //string yourname;
    char pc1[30][BUF_SIZE];
    char pc2[30][BUF_SIZE];
    char pc3[30][BUF_SIZE];
    char user[30][BUF_SIZE];
    int b[30][4];
    int ab,cd,ef,gh;
    int one,two,three,four;
    bool hack;
};

//shuttle
void card::shuttle(int *array, int Size)
{
    srand((unsigned)time(NULL));
    j1=(rand()%4)+1;
    rand(); // 先抽掉一個亂數

    for(i=0; i!=Size; i++){
       // 取出第 pos 張牌
       // pos = rand()%52; // worst
       pos = (int) (N*(double)rand()/(RAND_MAX+1.0)); // better
       // 將第 i 張牌與第 pos 張牌交換
       SWAP(array[i], array[pos]); 
    }
    j2=(rand()%4)+1;
    //cout<<"j1= \n"<<j1<<endl;
    //cout<<"j2= \n"<<j2<<endl;
    for(i=0;i<30;i++){
        strcpy(pc1[i],"0");
        strcpy(pc2[i],"0");
        strcpy(pc3[i],"0");
        strcpy(user[i],"0");
    }
    for(i=0;i<30;i++){
        for(int j=0;j<4;j++){
            b[i][j]=9;
        }
    }
}

//sendcard
void card::sendcard(int *poker, int Size)
{
    int i,flower;
    cout<<"PC 1:\n"<<endl;
    for(i=0; i<52 ; i++) {
        // 顯示花色, flower_index = poker[i] % 4
        flower= poker[i]% 4;
        b[i][i/13]=flower;
        if(flower==0) cout<<"♠";
        if(flower==1) cout<<"♥";
        if(flower==2) cout<<"♣";
        if(flower==3) cout<<"♦";
        // 顯示點數, number_index = poker[i] / 4
        printf("%s", number[ poker[i] >> 2 ]); // faster
        if(i<=12){
            b[i][0]=poker[i]% 4;
            strcpy(pc1[i],(number[ poker[i] >> 2]));
            //printf("%s",pc1[i]);
            
        }
        if(i>=13&&i<=25){
            b[i-13][1]=poker[i]% 4;
            strcpy(pc2[i-13],(number[ poker[i] >> 2]));
            //printf("%s",pc2[i-13]);
        }
        if(i>=26&&i<=38){
            b[i-26][2]=poker[i]% 4;
            strcpy(pc3[i-26],(number[ poker[i] >> 2]));
            //printf("%s",pc3[i-26]);
        }
        if(i>=39){
            b[i-39][3]=poker[i]% 4;
            strcpy(user[i-39],(number[ poker[i] >> 2]));
            //printf("%s",user[i-39]);
        }
        //if(i%5==4) putchar('\n');
        if(i==12){
            if(j1==1){
                cout<<"\033[33m ★\033[0m";
                strcpy(pc1[13],"B");
                b[13][0]=4; 
            }
            if(j2==1){
                cout<<"\033[33m ★\033[0m";
                if(strcmp(pc1[13],"B")==0){
                    strcpy(pc1[14],"B");
                    b[14][0]=5;
                }
                else{
                    b[13][0]=4; 
                    strcpy(pc1[13],"B");    
                }
            }
            cout<<"\nPC 2:\n"<<endl;
        }
        if(i==25){
            if(j1==2){
                cout<<"\033[33m ★\033[0m";
                strcpy(pc2[13],"B");
                b[13][1]=4;     
            }
            if(j2==2){
                cout<<"\033[33m ★\033[0m";
                if(strcmp(pc2[13],"B")==0){
                    strcpy(pc2[14],"B");
                    b[14][1]=5; 
                }
                else{
                    b[13][1]=4;
                    strcpy(pc2[13],"B");    
                }
            }
            cout<<"\nPC 3:\n"<<endl;
        }
        if(i==38){
            if(j1==3){
                cout<<"\033[33m ★\033[0m";
                strcpy(pc3[13],"B");
                b[13][2]=4;
            }
            if(j2==3){
                cout<<"\033[33m ★\033[0m";
                if(strcmp(pc3[13],"B")==0){
                    strcpy(pc3[14],"B");
                    b[14][2]=5;
                }
                else{
                    b[13][2]=4;
                    strcpy(pc3[13],"B");
                }
            }
            cout<<"\nYour's Card:\n"<<endl;
        }if(i==51){
            if(j1==4){
                cout<<"\033[33m ★\033[0m";
                strcpy(user[13],"B");
                b[13][3]=4; 
            }
            if(j2==4){
                cout<<"\033[33m ★\033[0m";
                if(strcmp(user[13],"B")==0){
                    strcpy(user[14],"B");
                    b[14][3]=5;
                }
                else{
                    b[13][3]=4;
                    strcpy(user[13],"B");
                }
            }
        }
    }
}
//selectcard
void card::selectcard(int selectwho,int num){
    //cout<<"1selectwho= "<<selectwho<<endl;
    switch(selectwho){
        case 1:
            for(i=0;i<30;i++){
                if(strcmp(pc1[i],"0")==0){
                    if(num>=i){break;}
                }
            }
            for(int j=0;j<30;j++){
                if(num>=i) {
                    cout<<"No This Card"<<endl;
                    break;}
                if(strcmp(user[j],"0")==0){
                    b[j][3]=b[num-1][0];
                    strcpy(user[j],pc1[num-1]);
                    for(i=num-1;i<30;i++){
                        strcpy(pc1[i],pc1[i+1]);
                        b[i][0]=b[i+1][0];
                    }
                    strcpy(pc1[29],"0");
                    break;
                }
            }
            break;
        case 2:
            for(i=0;i<30;i++){
                if(strcmp(pc2[i],"0")==0){
                    if(num>=i){break;}
                }
            }
            for(int j=0;j<30;j++){
                    if(num>=i) {
                        cout<<"No This Card"<<endl;
                        break;}
                    if(strcmp(user[j],"0")==0){
                        b[j][3]=b[num-1][1];
                        strcpy(user[j],pc2[num-1]);
                        for(i=num-1;i<30;i++){
                            strcpy(pc2[i],pc2[i+1]);
                            b[i][1]=b[i+1][1];
                        }
                        strcpy(pc2[29],"0");
                        break;
                    }
                }
            break;
        case 3:
            for(i=0;i<30;i++){
                if(strcmp(pc3[i],"0")==0){
                    if(num>=i){break;}
                }
            }
            for(int j=0;j<30;j++){
                if(num>=i) {
                    cout<<"No This Card"<<endl;
                    break;}
                if(strcmp(user[j],"0")==0){
                    b[j][3]=b[num-1][2];
                    strcpy(user[j],pc3[num-1]);
                    for(i=num-1;i<30;i++){
                        strcpy(pc3[i],pc3[i+1]);
                        b[i][2]=b[i+1][2];
                    }
                    strcpy(pc3[29],"0");
                    break;
                }
            }
            break;
        default:
            break;
    }
}
//display
void card::display(void){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"PC 1\n"<<endl;
    for(i=0;i<30;i++){
        if(strcmp(pc1[i],"0")==0) break;
        //if(b[i][0]==9) break;
        if(strcmp(pc1[i],"B")==0){
            cout<<"\033[33m ★\033[0m";
            continue;
        }
        if(b[i][0]==0) cout<<"♠";
        if(b[i][0]==1) cout<<"♥";
        if(b[i][0]==2) cout<<"♣";
        if(b[i][0]==3) cout<<"♦";
        printf("%s",pc1[i]);
    }
    cout<<"\nPC 2\n"<<endl;
    for(i=0;i<30;i++){
        if(strcmp(pc2[i],"0")==0) break;
        //if(b[i][1]==9) break;
        if(strcmp(pc2[i],"B")==0){
            cout<<"\33[33m ★\033[0m";
            continue;
        }
        if(b[i][1]==0) cout<<"♠";
        if(b[i][1]==1) cout<<"♥";
        if(b[i][1]==2) cout<<"♣";
        if(b[i][1]==3) cout<<"♦";
        printf("%s",pc2[i]);
    }
    cout<<"\nPC 3\n"<<endl;
    for(i=0;i<30;i++){
        if(strcmp(pc3[i],"0")==0) break;
        //if(b[i][2]==9) break;
        if(strcmp(pc3[i],"B")==0){
            cout<<"\33[33m ★\033[0m";
            continue;
        }
        if(b[i][2]==0) cout<<"♠";
        if(b[i][2]==1) cout<<"♥";
        if(b[i][2]==2) cout<<"♣";
        if(b[i][2]==3) cout<<"♦";
        printf("%s",pc3[i]);
    }
    cout<<"\nYour's Card\n"<<endl;
    for(i=0;i<30;i++){
        if(strcmp(user[i],"0")==0) break;
        //if(b[i][3]==9) break;
        if(strcmp(user[i],"B")==0){
            cout<<"\33[33m ★\033[0m";
            continue;
        }
        if(b[i][3]==0) cout<<"♠";
        if(b[i][3]==1) cout<<"♥";
        if(b[i][3]==2) cout<<"♣";
        if(b[i][3]==3) cout<<"♦";
        printf("%s",user[i]);
    }
    cout<<"\n------------------------------------------------------"<<endl;
}
//pcselect
void card::pcselect(int selectwho){
    ab=0;
    cd=0;
    ef=0;
    gh=0;
    for(i=0;i<30;i++){
        if(strcmp(pc1[i],"0")==0){
            one+=1;
            if(one==30) {ab=1;}
        }
        if(strcmp(pc2[i],"0")==0){
            two+=1;
            if(two==30) {cd=1;}
        }
        if(strcmp(pc3[i],"0")==0){
            three+=1;
            if(three==30) {ef=1;}
        }
        if(strcmp(user[i],"0")==0){
            four+=1;
            if(four==30) {gh=1;}
        }
    }
    switch(selectwho){
        num=0;
        case 1:
            for(i=0;i<30;i++){
                if(strcmp(pc2[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //pc2->pc1
            for(int j=0;j<30;j++){
                if(cd==1) {break;}
                if(strcmp(pc1[j],"0")==0){
                    b[j][0]=b[num][1];
                    strcpy(pc1[j],pc2[num]);
                    for(i=num;i<30;i++){
                        strcpy(pc2[i],pc2[i+1]);
                        b[i][1]=b[i+1][1];
                    }
                    strcpy(pc2[29],"0");
                    b[29][1]=9;
                    break;
                }
            }
            for(i=0;i<30;i++){
                if(strcmp(pc3[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //pc3->pc2
            for(int j=0;j<30;j++){
                if(ef==1) {break;}
                if(strcmp(pc2[j],"0")==0){
                    b[j][1]=b[num][2];
                    strcpy(pc2[j],pc3[num]);
                    for(i=num;i<30;i++){
                        strcpy(pc3[i],pc3[i+1]);
                        b[i][2]=b[i+1][2];
                    }
                    strcpy(pc3[29],"0");
                    b[29][2]=9;
                    break;
                }
            }
            for(i=0;i<30;i++){
                if(strcmp(user[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //user->pc3
            for(int j=0;j<30;j++){
                if(gh==1) {break;}
                if(strcmp(pc3[j],"0")==0){
                    b[j][2]=b[num][3];
                    strcpy(pc3[j],user[num]);
                    for(i=num;i<30;i++){
                        strcpy(user[i],user[i+1]);
                        b[i][3]=b[i+1][3];
                    }
                    strcpy(pc3[29],"0");
                    b[29][3]=9;
                    break;
                }
            }
            break;
        case 2:
            for(i=0;i<30;i++){
                if(strcmp(pc3[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //pc3->pc2
            for(int j=0;j<30;j++){
                if(ef==1) {break;}
                if(strcmp(pc2[j],"0")==0){
                    b[j][1]=b[num][2];
                    strcpy(pc2[j],pc3[num]);
                    for(i=num;i<30;i++){
                        strcpy(pc3[i],pc3[i+1]);
                        b[i][2]=b[i+1][2];
                    }
                    strcpy(pc3[29],"0");
                    b[29][2]=9;
                    break;
                }
            }
            for(i=0;i<30;i++){
                if(strcmp(pc1[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //pc1->pc3
            for(int j=0;j<30;j++){
                if(ab==1) {break;}
                if(strcmp(pc3[j],"0")==0){
                    b[j][2]=b[num][0];
                    strcpy(pc3[j],pc1[num]);
                    for(i=num;i<30;i++){
                        strcpy(pc1[i],pc1[i+1]);
                        b[i][0]=b[i+1][0];
                    }
                    strcpy(pc1[29],"0");
                    b[29][0]=9;
                    break;
                }
            }
            for(i=0;i<30;i++){
                if(strcmp(user[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //user->pc1
            for(int j=0;j<30;j++){
                if(gh==1) {break;}
                if(strcmp(pc1[j],"0")==0){
                    b[j][0]=b[num][3];
                    strcpy(pc1[j],user[num]);
                    for(i=num;i<30;i++){
                        strcpy(user[i],user[i+1]);
                        b[i][3]=b[i+1][3];
                    }
                    strcpy(user[29],"0");
                    b[29][3]=9;
                    break;
                }
            }
            break;
        case 3:
            for(i=0;i<30;i++){
                if(strcmp(pc1[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //pc1->pc3
            for(int j=0;j<30;j++){
                if(ab==1) {break;}
                if(strcmp(pc3[j],"0")==0){
                    b[j][2]=b[num][0];
                    strcpy(pc3[j],pc1[num]);
                    for(i=num;i<30;i++){
                        strcpy(pc1[i],pc1[i+1]);
                        b[i][0]=b[i+1][0];
                    }
                    strcpy(pc1[29],"0");
                    b[29][0]=9;
                    break;
                }
            }
            for(i=0;i<30;i++){
                if(strcmp(pc2[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //pc2->pc1
            for(int j=0;j<30;j++){
                if(cd==1) {break;}
                if(strcmp(pc1[j],"0")==0){
                    b[j][0]=b[num][1];
                    strcpy(pc1[j],pc2[num]);
                    for(i=num;i<30;i++){
                        strcpy(pc2[i],pc2[i+1]);
                        b[i][1]=b[i+1][1];
                    }
                    strcpy(pc2[29],"0");
                    b[29][1]=9;
                    break;
                }
            }
            for(i=0;i<30;i++){
                if(strcmp(user[i],"0")==0){
                    num=rand()%i;
                    break;
                }
            }
            //user->pc2
            for(int j=0;j<30;j++){
                if(gh==1) {break;}
                if(strcmp(pc2[j],"0")==0){
                    b[j][1]=b[num][3];
                    strcpy(pc2[j],user[num]);
                    for(i=num;i<30;i++){
                        strcpy(user[i],user[i+1]);
                        b[i][3]=b[i+1][3];
                    }
                    strcpy(user[29],"0");
                    b[29][3]=9;
                    break;
                }
            }
            break;
        default:
            break;
    }
}
//clear
void card::clear(){
    for(i=0;i<30;i++){
        for(int j=i+1;j<30;j++){
            if(strcmp(user[i],user[j])==0&&strcmp(user[i],"B")!=0){
                //cout<<"i= "<<i<<"\nj= "<<j<<"\n"<<endl;
                for(int k=j;k<30;k++){
                    strcpy(user[k],user[k+1]);
                    b[k][3]=b[k+1][3];
                }
                for(int k=i;k<30;k++){
                    strcpy(user[k],user[k+1]);
                    b[k][3]=b[k+1][3];   
                }
                strcpy(user[28],"0");
                strcpy(user[29],"0");
                b[28][3]=9;
                b[29][3]=9;
            }
        }
    }
    for(i=0;i<30;i++){
        for(int j=i+1;j<30;j++){
            if(strcmp(pc1[i],pc1[j])==0&&strcmp(pc1[i],"B")!=0){
                //cout<<"i= "<<i<<"\nj= "<<j<<"\n"<<endl;
                for(int k=j;k<30;k++){
                    strcpy(pc1[k],pc1[k+1]);
                    b[k][0]=b[k+1][0];
                }
                for(int k=i;k<30;k++){
                    strcpy(pc1[k],pc1[k+1]);
                    b[k][0]=b[k+1][0];
                }
                strcpy(pc1[28],"0");
                strcpy(pc1[29],"0");
                b[28][0]=9;
                b[29][0]=9;
            }
        }
    }
    for(i=0;i<30;i++){
        for(j=i+1;j<30;j++){
            if(strcmp(pc2[i],pc2[j])==0&&strcmp(pc2[i],"B")!=0){
                //cout<<"i= "<<i<<"\nj= "<<j<<"\n"<<endl;
                for(int k=j;k<30;k++){
                    strcpy(pc2[k],pc2[k+1]);
                    b[k][1]=b[k+1][1];
                }
                for(int k=i;k<30;k++){
                    strcpy(pc2[k],pc2[k+1]);
                    b[k][1]=b[k+1][1];
                }
                strcpy(pc2[28],"0");
                strcpy(pc2[29],"0");
                b[28][1]=9;
                b[29][1]=9;
            }
        }
    }
    for(i=0;i<30;i++){
        for(j=i+1;j<30;j++){
            if(strcmp(pc3[i],pc3[j])==0&&strcmp(pc3[i],"B")!=0){
                //cout<<"i= "<<i<<"\nj= "<<j<<"\n"<<endl;
                for(int k=j;k<30;k++){
                    strcpy(pc3[k],pc3[k+1]);
                    b[k][2]=b[k+1][2];
                }
                for(int k=i;k<30;k++){
                    strcpy(pc3[k],pc3[k+1]);
                    b[k][2]=b[k+1][2];
                }
                strcpy(pc3[28],"0");
                strcpy(pc3[29],"0");
                b[28][2]=9;
                b[29][2]=9;
            }
        }
    }
}
//judge
void card::judge(void){
    //int ker=0;
    ab=0;
    cd=0;
    ef=0;
    gh=0;
    hack=false;
    for(i=0;i<30;i++){
        if(strcmp(pc1[i],"0")==0||b[i][0]==9){
            ab+=1;
        }
        if(strcmp(pc2[i],"0")==0||b[i][1]==9){
            cd+=1;
        }
        if(strcmp(pc3[i],"0")==0||b[i][2]==9){
            ef+=1;
        }
        if(strcmp(user[i],"0")==0||b[i][3]==9){
            gh+=1;
        }
    }
    if(gh==30){
        //cout<<"You Wins The Game"<<endl;
            cout<<"\033[33m   ********************************************************************\033[0m"<<endl;
            cout<<"\033[33m   * *      * ********  *      *  *                   * *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *      *  *      *   *                 *   *  **     *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *      *  *      *    *       *       *    *  * *    *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *      *  *      *     *      *      *     *  *  *   *  *\033[0m"<<endl;
            cout<<"\033[33m   * ******** *      *  *      *      *     *     *      *  *   *  *  *\033[0m"<<endl;
            cout<<"\033[33m   *    *     *      *  *      *       *   * *   *       *  *    * *  *\033[0m"<<endl;
            cout<<"\033[33m   *    *     *      *  *      *        * *   * *        *  *     **  *\033[0m"<<endl;
            cout<<"\033[33m   *    *     ********  ********         *     *        *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   ********************************************************************\033[0m"<<endl;
        hack=true;
    }
    if(gh!=30){
        if(ab==30){
            //cout<<"PC1 Wins The Game!";
            cout<<"\033[33m   *******************************************************************\033[0m"<<endl;
            cout<<"\033[33m   * ******** ********     *     *                   * *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *           *       *                 *   *  **     *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *          **        *       *       *    *  * *    *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *         * *         *      *      *     *  *  *   *  *\033[0m"<<endl;
            cout<<"\033[33m   * ******** *           *          *     *     *      *  *   *  *  *\033[0m"<<endl;
            cout<<"\033[33m   * *        *           *           *   * *   *       *  *    * *  *\033[0m"<<endl;
            cout<<"\033[33m   * *        *           *            * *   * *        *  *     **  *\033[0m"<<endl;
            cout<<"\033[33m   * *        ********  *****           *     *        *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   *******************************************************************\033[0m"<<endl;
            hack=true;
        }
        if(cd==30){
            cout<<"\033[33m   *******************************************************************\033[0m"<<endl;
            cout<<"\033[33m   * ******** ********  *****    *                   * *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *             *     *                 *   *  **     *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *             *      *       *       *    *  * *    *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *             *       *      *      *     *  *  *   *  *\033[0m"<<endl;
            cout<<"\033[33m   * ******** *         *****        *     *     *      *  *   *  *  *\033[0m"<<endl;
            cout<<"\033[33m   * *        *         *             *   * *   *       *  *    * *  *\033[0m"<<endl;
            cout<<"\033[33m   * *        *         *              * *   * *        *  *     **  *\033[0m"<<endl;
            cout<<"\033[33m   * *        ********  *****           *     *        *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   *******************************************************************\033[0m"<<endl;
            //cout<<"PC2 Wins The Game!";
            hack=true;
        }
        if(ef==30){
            cout<<"\033[33m   *******************************************************************\033[0m"<<endl;
            cout<<"\033[33m   * ******** ********  *****    *                   * *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *             *     *                 *   *  **     *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *             *      *       *       *    *  * *    *  *\033[0m"<<endl;
            cout<<"\033[33m   * *      * *             *       *      *      *     *  *  *   *  *\033[0m"<<endl;
            cout<<"\033[33m   * ******** *         *****        *     *     *      *  *   *  *  *\033[0m"<<endl;
            cout<<"\033[33m   * *        *             *         *   * *   *       *  *    * *  *\033[0m"<<endl;
            cout<<"\033[33m   * *        *             *          * *   * *        *  *     **  *\033[0m"<<endl;
            cout<<"\033[33m   * *        ********  *****           *     *        *** *      *  *\033[0m"<<endl;
            cout<<"\033[33m   *******************************************************************\033[0m"<<endl;
            //cout<<"PC3 Wins The Game!";
            hack=true;
        }
    }
}
bool card::hacky(){return hack;}
int main()
{
    card user,pc;
    int i, poker[N],selectnum,selectwho,num;
    char yes;
    bool hack;
    string yourname;
    cout<<"\033[33m W E L C O M E   T O: \033[0m"<<endl;
    cout<<"\033[33m      **************************************************************\033[0m"<<endl;
    cout<<"\033[33m      *  *********  ********  *******  *      *  *******  *******  *\033[0m"<<endl;
    cout<<"\033[33m      *      *      *      *  *        *    *    *        *     *  *\033[0m"<<endl;
    cout<<"\033[33m      *      *      *      *  *        *  *      *        *     *  *\033[0m"<<endl;
    cout<<"\033[33m      *      *      *      *  *        **        *        *    *   *\033[0m"<<endl;
    cout<<"\033[33m      *      *      *      *  *        **        *******  ****     *\033[0m"<<endl;
    cout<<"\033[33m      *   *  *      *      *  *        *  *      *        *  *     *\033[0m"<<endl;
    cout<<"\033[33m      *    * *      *      *  *        *    *    *        *    *   *\033[0m"<<endl;
    cout<<"\033[33m      *      *      ********  *******  *      *  *******  *     *  *\033[0m"<<endl;
    cout<<"\033[33m      **************************************************************\033[0m"<<endl;
    cout<<"\033[33m                                          (Written by Jack Kuo & Sue Yo Man)\033[0m\n Ready to start ?[Y/N]";
    cin>>yes;
    if(yes!='y'&&yes!='Y') {
        return 0;
    }
    cout<<"Please enter your name ";
    getchar();
    getline(cin,yourname);
    cout<<" Hello  "<<yourname<<" !  Nice to meet you!"<<endl;
    cout<<"Continue ?[Y/N]";
    cin>>yes;
    if(yes!='y'&&yes!='Y') {
        return 0;
    }
    for(i=0; i!=N; i++) poker[i] = i;
    user.shuttle(poker, N);
    user.sendcard(poker, N);
    while(1){
        cout<<"\nNow is your turn.\nWhose cards do you want to select? (enter 4 to clear)  ";
        cin>>selectwho;
        if(selectwho!=1&&selectwho!=2&&selectwho!=3&&selectwho!=4){
            cout<<"No this player, Please enter again";
            continue;
        }
        if(selectwho==4){
            user.clear();
            user.display();
            user.judge();
            if(user.hacky()==true){
            cout<<"\nThe Game is over!\nBut you can still play this game"<<endl;
            }
            continue;
        }
        cout<<"Which card you want to select? ";
        cin>>num;
        user.selectcard(selectwho,num);
        user.display();
        cout<<"Now turns to computer "<<endl;
        user.pcselect(selectwho);
        user.display();
        user.judge();
        //user.hacky();
        if(user.hacky()==true){
            cout<<"\nThe Game is over!\nBut you can still play this game"<<endl;
        }
    }
    return 0;
}
