#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    char s[101],catp[50],catena[50][50],carboh[100][100],rad[15],v;

    int i,j,n,k,nrC,sfcatp,pozrad[20],m=1,b,o,pozalchene=0;

    bool verificare1=false,verificare2=false;

    ifstream f("denumiri_catene.txt");
    f.get(s,101);
    //cout<<s<<endl;
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("1234567890",s[i]))
            verificare1=true;
    }
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("l",s[i]))
            verificare2=true;
    }
    if(verificare1==true&&verificare2==true)
    {

    i=strlen(s)-1;n=0;
    while(s[i]!='l')
    {
    i--;
    }
    sfcatp=i+1;
    //cout<<sfcatp<<endl;

    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
        {
            catena[i][j]=' ';
        }
    }
    for(j=sfcatp;j<strlen(s);j++)
    {
        catp[n]=s[j];
        n++;
    }
    catp[n]=NULL;
    //cout<<catp<<endl;
    strcpy(carboh[1],"metan"); strcpy(carboh[2],"etan"); strcpy(carboh[3],"propan"); strcpy(carboh[4],"butan");
     strcpy(carboh[5],"pentan"); strcpy(carboh[6],"hexan"); strcpy(carboh[7],"heptan"); strcpy(carboh[8],"octan");
      strcpy(carboh[9],"nonan"); strcpy(carboh[10],"decan");
      strcpy(carboh[11],"etena");
      strcpy(carboh[12],"propena"); strcpy(carboh[13],"-1-butena"); strcpy(carboh[14],"-2-butena"); strcpy(carboh[15],"-1-pentena");
      strcpy(carboh[16],"-2-pentena"); strcpy(carboh[17],"-1-hexena"); strcpy(carboh[18],"-2-hexena"); strcpy(carboh[19],"-3-hexena");
      strcpy(carboh[20],"-1-heptena"); strcpy(carboh[21],"-2-heptena"); strcpy(carboh[22],"-3-heptena"); strcpy(carboh[23],"-1-octena");
      strcpy(carboh[24],"-2-octena"); strcpy(carboh[25],"-3-octena"); strcpy(carboh[26],"-4-octena"); strcpy(carboh[27],"-1-nonena");
      strcpy(carboh[28],"-2-nonena"); strcpy(carboh[29],"-3-nonena"); strcpy(carboh[30],"-4-nonena");
      strcpy(carboh[31],"-1-decena");
      strcpy(carboh[32],"-2-decena"); strcpy(carboh[33],"-3-decena"); strcpy(carboh[34],"-4-decena"); strcpy(carboh[35],"-5-decena");
      i=1;
      while(strcmp(carboh[i],catp)!=0)
      {
          i++;
      }
      if(i<=10)
      {
      nrC=i;
      }
      else if(i>10)
      {
          pozalchene=s[sfcatp+1]-48;
         // cout<<endl<<"pozalchene="<<pozalchene<<endl;
          if(i==11)
            nrC=2;
          if(i==12)
            nrC=3;
          if(i>=13&&i<=14)
          nrC=4;
          if(i>=15&&i<=16)
            nrC=5;
          if(i>=17&&i<=19)
            nrC=6;
          if(i>=20&&i<=22)
            nrC=7;
          if(i>=23&&i<=26)
            nrC=8;
          if(i>=27&&i<=30)
            nrC=9;
          if(i>=31&&i<=35)
            nrC=10;
      }
      //cout<<nrC<<endl;
      k=10;j=1;
    while(j<=nrC)
    {

        if(j==1)
        {
            if(j==pozalchene)
            {
               // cout<<"A INTRAT";
            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='2';
            k++;
            catena[25][k]='=';
            k++;
             catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='-';
            k++;
            j++;
            }
            else{
            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='3';
            k++;
            catena[25][k]='-';
            k++;
            }
        }
        else if(j==nrC-1&&pozalchene>0)
        {

            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='3';
            k++;
            catena[25][k]=NULL;
        }
        else if(j==nrC&&pozalchene==0)
            {

            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='3';
            k++;
            catena[25][k]=NULL;
        }
        else if(j>1&&j<nrC)
        {
            if(j==pozalchene)
            {
               // cout<<"A INTRAT"<<endl<<"pozalchene="<<s[pozalchene]-48<<endl<<"j="<<j<<endl;
            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='=';
            k++;
            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
            catena[25][k]='-';
            k++;
            j++;
            }
            catena[25][k]='C';
            k++;
            catena[25][k]='H';
            k++;
             catena[25][k]='2';
            k++;
            catena[25][k]='-';
            k++;
        }
        j++;
    }
    s[sfcatp]=' ';
   // cout<<s<<endl;
    i=0;j=1;v=1;
    while(s[i]!=' ')
    {n=0;
        //incepand de aici
        while(strchr("1234567890",s[i])||s[i]==',')
        {
         if(strchr("1234567890",s[i]))
         {
            pozrad[j]=s[i]-48;
            j++;
            i++;
           // cout<<pozrad[j-1];
         }
         else if(s[i]==',')
            i++;
        }
        //pana aici gasesc pozitiile unde se afla radicalii mei pe catena
        //cout<<endl;
     i++;
     //incepand de aici
        while(s[i]!='-'&&s[i]!=' '&&strchr("1234567890",s[i])==0)
        {
            rad[n]=s[i];
            //cout<<rad[n];
            i++;
            n++;
        }
        rad[n]=NULL;
        //pana aici gasesc ce radicali am pe catena
        //cout<<endl<<endl;
        if(strcmp(rad,"etil")==0)
        {   b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"dietil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
        if(catena[24][b]==' '&&catena[23][b]==' ')
        {
            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';

        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
        v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

            if(catena[24][b]==' '&&catena[23][b]==' ')
        {
            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';

        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
        v++;
            if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"trietil")==0)
        {
              b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
             if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
            if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
            if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
             b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
           if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"tetraetil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

            if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


            if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
            if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
             {
              catena[25][b]='C';
                catena[25][b-1]=' ';
             }
             b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


           if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
             b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


           if(catena[24][b]==' '&&catena[23][b]==' ')
             {

            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='3';
             }
              else if(catena[26][b]==' '&&catena[27][b]==' ')
        {
              catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='3';

        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"metil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

        if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"dimetil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
            if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
             {
                catena[25][b+1]=' ';
                catena[25][b-1]='C';
             }
                if((catena[26][b]=='|')&&(catena[24][b]=='|'))
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }

             b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;
             if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"trimetil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
               if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


            if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


           if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
            if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"tetrametil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
               if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
            if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

            if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;


            if(catena[24][b]==' '&&catena[23][b]==' ')
        {
             catena[24][b]='|';
             catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
            {
             catena[26][b]='|';
             catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"izopropil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

        if(catena[27][b-5]==' '&&catena[27][b+4]==' ')
        {
            catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='-';
            catena[27][b+2]='C';
            catena[27][b+3]='H';
             catena[27][b+4]='3';
             catena[27][b-2]='-';
            catena[27][b-3]='3';
            catena[27][b-4]='H';
            catena[27][b-5]='C';
        }
        else if(catena[23][b-5]=' '&&catena[23][b+4]==' '&&catena[24][b]==' ')
        {
             catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='-';
            catena[23][b+2]='C';
            catena[23][b+3]='H';
             catena[23][b+4]='3';
             catena[23][b-2]='-';
            catena[23][b-3]='3';
            catena[23][b-4]='H';
            catena[23][b-5]='C';
        }
            v++;
              if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }
        else if(strcmp(rad,"propil")==0)
        {
            b=0;o=0;
            while(o!=pozrad[v])
            {
                if(catena[25][b-1]=='C')
                    o++;
                b++;
            }
            b=b-1;

        if(catena[24][b]==' '&&catena[23][b]==' ')
        {


            catena[24][b]='|';
            catena[23][b-1]='C';
            catena[23][b]='H';
            catena[23][b+1]='2';
            catena[22][b]='|';
             catena[21][b-1]='C';
            catena[21][b]='H';
            catena[21][b+1]='2';
             catena[20][b]='|';
             catena[19][b-1]='C';
            catena[19][b]='H';
            catena[19][b+1]='3';
        }
        else if(catena[26][b]==' '&&catena[27][b]==' ')
             {


            catena[26][b]='|';
            catena[27][b-1]='C';
            catena[27][b]='H';
            catena[27][b+1]='2';
            catena[28][b]='|';
             catena[29][b-1]='C';
            catena[29][b]='H';
            catena[29][b+1]='2';
             catena[30][b]='|';
             catena[31][b-1]='C';
            catena[31][b]='H';
            catena[31][b+1]='3';
        }
            v++;
             if((catena[26][b]=='|'||catena[24][b]=='|')&&strchr("123456789",catena[25][b+1]))
                catena[25][b+1]=' ';
                if(catena[26][b]=='|'&&catena[24][b]=='|')
            {
                catena[25][b]='C';
                catena[25][b+1]=' ';
                catena[25][b-1]=' ';
            }
              if((catena[25][b+1])=='='||(catena[25][b-2]=='='))
              {
              catena[25][b]='C';
                catena[25][b-1]=' ';
              }
        }

    }
for(i=15;i<30;i++)
    {
        for(j=0;j<50;j++)
        {
            cout<<catena[i][j];
        }
        cout<<endl;
    }
    }
    else
    {
        strcpy(carboh[1],"metan"); strcpy(carboh[2],"etan"); strcpy(carboh[3],"propan"); strcpy(carboh[4],"butan");
     strcpy(carboh[5],"pentan"); strcpy(carboh[6],"hexan"); strcpy(carboh[7],"heptan"); strcpy(carboh[8],"octan");
      strcpy(carboh[9],"nonan"); strcpy(carboh[10],"decan"); strcpy(carboh[11],"etena");
      strcpy(carboh[12],"propena"); strcpy(carboh[13],"1-butena"); strcpy(carboh[14],"2-butena"); strcpy(carboh[15],"1-pentena");
      strcpy(carboh[16],"2-pentena"); strcpy(carboh[17],"1-hexena"); strcpy(carboh[18],"2-hexena"); strcpy(carboh[19],"3-hexena");
      strcpy(carboh[20],"1-heptena"); strcpy(carboh[21],"2-heptena"); strcpy(carboh[22],"3-heptena"); strcpy(carboh[23],"1-octena");
      strcpy(carboh[24],"2-octena"); strcpy(carboh[25],"3-octena"); strcpy(carboh[26],"4-octena"); strcpy(carboh[27],"1-nonena");
      strcpy(carboh[28],"2-nonena"); strcpy(carboh[29],"3-nonena"); strcpy(carboh[30],"4-nonena");
      strcpy(carboh[31],"1-decena");
      strcpy(carboh[32],"2-decena"); strcpy(carboh[33],"3-decena"); strcpy(carboh[34],"4-decena"); strcpy(carboh[35],"5-decena");
      for(i=1;i<=35;i++)
      {
          if(strcmp(s,carboh[i])==0)
          {
              if(strcmp(s,"metan")==0)
                cout<<"CH3";
              else if(i<=10){
              cout<<"CH3-";
              for(j=1;j<i-1;j++)
              {
                cout<<"CH2-";
              }
              cout<<"CH3";
              }
              else if(i>10&&i<=35)
              {
                if(strcmp(s,"etena")==0)
                    cout<<"CH2=CH2";
                if(strcmp(s,"propena")==0)
                    cout<<"CH2=CH-CH3";
                if(strcmp(s,"1-butena")==0)
                    cout<<"CH2=CH-CH2-CH3";
                if(strcmp(s,"2-butena")==0)
                    cout<<"CH3-CH=CH-CH3";
                if(strcmp(s,"1-pentena")==0)
                    cout<<"CH2=CH-CH2-CH2-CH3";
                if(strcmp(s,"2-pentena")==0)
                    cout<<"CH3-CH=CH-CH2-CH3";
                if(strcmp(s,"1-hexena")==0)
                    cout<<"CH2=CH-CH2-CH2-CH2-CH3";
                if(strcmp(s,"2-hexena")==0)
                    cout<<"CH3-CH=CH-CH2-CH2-CH3";
                if(strcmp(s,"3-hexena")==0)
                    cout<<"CH3-CH2-CH=CH-CH2-CH3";
                if(strcmp(s,"1-heptena")==0)
                    cout<<"CH2=CH-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"2-heptena")==0)
                    cout<<"CH3-CH=CH-CH2-CH2-CH2-CH3";
                if(strcmp(s,"3-heptena")==0)
                    cout<<"CH3-CH3-CH=CH-CH2-CH2-CH3";
                if(strcmp(s,"1-octena")==0)
                    cout<<"CH2=CH-CH2-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"2-octena")==0)
                    cout<<"CH3-CH=CH-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"3-octena")==0)
                    cout<<"CH3-CH2-CH=CH-CH2-CH2-CH2-CH3";
                if(strcmp(s,"4-octena")==0)
                    cout<<"CH3-CH2-CH2-CH=CH-CH2-CH2-CH3";
                if(strcmp(s,"1-nonena")==0)
                    cout<<"CH2=CH-CH2-CH2-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"2-nonena")==0)
                    cout<<"CH3-CH=CH-CH2-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"3-nonena")==0)
                    cout<<"CH3-CH2-CH=CH-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"4-nonena")==0)
                    cout<<"CH3-CH2-CH2-CH=CH-CH2-CH2-CH2-CH3";
                if(strcmp(s,"1-decena")==0)
                    cout<<"CH2=CH-CH2-CH2-CH2-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"2-decena")==0)
                    cout<<"CH3-CH=CH-CH2-CH2-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"3-decena")==0)
                    cout<<"CH3-CH2-CH=CH-CH2-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"4-decena")==0)
                    cout<<"CH3-CH2-CH2-CH=CH-CH2-CH2-CH2-CH2-CH3";
                if(strcmp(s,"5-decena")==0)
                    cout<<"CH3-CH2-CH2-CH2-CH=CH-CH2-CH2-CH2-CH3";

              }
          }
      }
    }
    return 0;
}
