#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    string ans;
    while(cin>>ans){
        unordered_map<string,int> hash;

//        for(int i=0;i<ans.size();i++){
//            if(ans[i]!=',' &&   (tolower(ans[i]) < 'a' || tolower(ans[i])>'z' ) ){
//                cout<<"error.0001"<<endl;
//
//
//            }
//        }

        int left=0,right=0;
        while(right<ans.size()){
            while(ans[right]!=','&&right<ans.size())
                right++;
            hash[ans.substr(left,right-left)]++;
            left=right+1;
            right++;
        }

        int max_val=INT_MIN;
        vector<string>res;
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->second>max_val){
                max_val=it->second;
                res.clear();
                res.push_back(it->first);

            }
            else if(max_val==it->second){
                res.push_back(it->first);
            }
        }//存入了得票最高的人的所有名字
//        sort(res.begin(),res.end());
//        cout<<res[0]<<endl;
        int flag=0;
        int num=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==','){
                num++;
            }
        }
        num++;

        if(num>=100 ){
            cout<<"error.0001"<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){

                if(ans[i]!=',' &&   (tolower(ans[i]) < 'a' || tolower(ans[i])>'z' ) ){
                    cout<<"error.0001"<<endl;
                    flag=1;
                }
            }
            if(flag==0){
                sort(res.begin(),res.end());
                cout<<res[0]<<endl;
            }
        }


    }
}