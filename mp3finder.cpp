#include<iostream>
#include<dirent.h>
#include<string>
#include<string.h>
using namespace std;
void recursive(string s){

string temp;

DIR *dir;
struct dirent *ent;
// cout<<"Enter the directory name\n";
// getline(cin,dirname);

if((  dir=opendir(s.c_str()) )   !=NULL){
	while((ent=readdir(dir))!=NULL){
		if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0 || ent->d_name[0]=='.')continue;
		if(ent->d_type==4){
            string temp1(ent->d_name);
			temp=s+"/"+temp1;
			recursive(temp);
		}
                 if(ent->d_type==DT_REG){
                       if(ent->d_name[strlen(ent->d_name)-1]=='3')
                      cout<<ent->d_name<<" "<<s<<endl;
                   }

	}

	closedir(dir);
}





}
int main(){



recursive(".");

}
