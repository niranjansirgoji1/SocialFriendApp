#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef char c;
typedef string st;
typedef map<long long,long long> mp1;
typedef vector<long long> vec;
typedef vector<vector<long long>> vec1;
using namespace std;





// here we define user class for storing data
class User{
   
   public:
   string name;
   string password;
   string gender;
   int age;
   ll id;
   int active;
   int pair_status;
   ll pair;
   
   public:
   User(){};
   
   public:
   User(string name1,string password1,string gender1,int age1,ll id1,int active1,int pair_status1,ll pair1){
      name=name1;
      password=password1;
      gender=gender1;
      age=age1;
      id=id1;
      active=active1;
      pair_status=pair_status1;
      pair=pair1;

   }
   
   public:
   string getname() {return name;}
   string getpassword() {return password;}
   int getage() {return age;}
   string getgender() {return gender;}
   ll getid() {return id;}
   int getactive() {return active;}
   bool getpair_status(){return pair_status;}
   ll get_pair(){return pair;}
};

// converting names to lowercase for comparison
string lowercase(string s){
  transform(s.begin(),s.end(),s.begin(),::tolower);
  return s;
}




// to add users
void adduser(vector<vector<ll>> &adj,map<ll,User>& users){
    cout<<"Enter your name"<<endl;
    string name1;
    cin>>name1;
    cout<<"Enter your password"<<endl;
    string password1;
    cin>>password1;
    cout<<"Enter your age"<<endl;
    int age1;
    cin>>age1;
    cout<<"Type your gender"<<endl;
    string gender1;
    cin>>gender1;

    User var;
    ll id1;
    id1=adj.size();

    name1=lowercase(name1);

    var=User(name1,password1,gender1,age1,id1,1,0,-1);
    users[id1]=var;
    
    vector<ll> userlist;
    adj.push_back(userlist);
    cout<<"Your Account has been succesfully registered"<<endl;
    cout<<"Name:" ;
    cout<<name1<<endl;
    cout<<"Gender:";
    cout<<gender1<<endl;
    cout<<"Age:";
    cout<<age1<<endl;
    cout<<"Id:";
    cout<<id1<<endl;
    cout<<"status:";
    cout<<"single"<<endl;

}




// to access data throught text file
void storeinidata(vector<vector<ll>>& adj,map<ll,User>& users){
      ifstream infile("data.txt");
      if (!infile.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }

        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            int id1, age1;
            string name1, password1, gender1;
            int active1;
            ll pair1;
            int pair_status1;
            ss>>id1>>name1>>password1>>age1>>gender1>>active1>>pair_status1>>pair1;

            
            User dat;
            name1=lowercase(name1);
            dat=User(name1,password1,gender1,age1,id1,active1,pair_status1,pair1);
            users[id1]=dat;

            
            ll friendID;
            vector<ll> temp;
            adj.push_back(temp);
            while (ss>>friendID) {
                adj[id1].push_back(friendID);
            }
        }

        infile.close();
}





// to export our data to file
void exportToFile(map<ll, User>& users, vector<vector<ll>>& adj, const string& filename) {
      ofstream ofile;
      ofile.open(filename);

      if(!ofile.is_open()){
        cout<<"Error opening file"<<endl;
      }
      else{
        for(auto it:users){
          User exp;
          exp=it.second;
          ofile<<it.first<<" "<<exp.name<<" "<<exp.password<<" "
          <<exp.age<<" "<<exp.gender<<" "<<exp.active<<" "
          <<exp.pair_status<<" "<<exp.pair<<" ";

         for(int i=0;i<adj[it.first].size();i++){
            ofile<<adj[it.first][i]<<" ";
         }
         ofile<<endl;
        }
      }
      ofile.close();
  }





// when user logs in it checks what to print 
int printuser(string password_in,int id_in,map<ll,User>& users){
       if(users.find(id_in)==users.end()){
          cout<<"Incorrect id"<<endl;
          return -1;
       }
       else if(users[id_in].getactive()==0){
         cout<<"User is inactive,activate your account"<<endl;
         return -1;
       }
       else{
          if(users[id_in].getpassword()!=password_in){
            cout<<"Incorrect password try again"<<endl;
            return -1;
          }
          else{

           if(users[id_in].get_pair()!=-1 && users[id_in].getpair_status()==0){
               ll lover=users[id_in].get_pair();

               cout<<users[lover].getname()<<" "<<users[lover].getage()<<" "<<users[lover].getgender()<<" ";
               cout<<"wants to connect with you";
               cout<<"  type yes to connect no to reject"<<endl;
               string interest;
               cin>>interest;
               interest=lowercase(interest);

               if(interest=="yes"){
                users[lover].pair=id_in;
                users[id_in].pair_status=1;
               }
               else if(interest=="no"){
                 users[id_in].pair=-1;
                 users[lover].pair_status=0;
               }
           }

            cout<<id_in<<" ";
            cout<<users[id_in].getname()<<" ";
            cout<<users[id_in].getage()<<" ";
            cout<<users[id_in].getgender()<<" ";
            
            if(users[id_in].getpair_status()==1){
              cout<<"paired"<<endl;
            }
            else{
              cout<<"single"<<endl;
            }

             if(users[id_in].get_pair()!=-1 && users[id_in].getpair_status()==1){
            ll lover=users[id_in].get_pair();

            cout<<"You are connected with:";
            cout<<users[lover].getname()<<" ";
            cout<<"Try to go out on a date and meet them to express your feelings"<<endl;
            
           }

            return 1;
          }
       }
}




// these are all for changing credentials
void changename(map<ll,User>& users,ll id_in){
    cout<<"Enter your new name"<<endl;
    string new_name;
    cin>>new_name;
    
    new_name=lowercase(new_name);
    users[id_in].name=new_name;
    return;
}

void changeage(map<ll,User>& users,ll id_in){
    cout<<"Enter your new age"<<endl;
    int new_age;
    cin>>new_age;

    users[id_in].age=new_age;
    return;
}

void changepassword(map<ll,User>& users,ll id_in){
    cout<<"Enter your new password"<<endl;
    string new_password;
    cin>>new_password;

    users[id_in].password=new_password;
    return;
}





// to show friends/connections
void showfriends(map<ll,User>& users,ll id_in,vector<vector<ll>>& adj){
     for(int i=0;i<adj[id_in].size();i++){
        cout<<users[adj[id_in][i]].getname()<<" ";
        cout<<users[adj[id_in][i]].getage()<<" ";
        cout<<users[adj[id_in][i]].getgender()<<" ";
        
        if(users[adj[id_in][i]].getpair_status()){
          cout<<"paired"<<endl;
        }
        else{
          cout<<"single"<<endl;
        }
     }
     return;
}



// suggestions
void suggestions(map<ll,User>& users,vector<vector<ll>> &adj,ll id_in){
   
  cout<<"suggestions"<<endl;
   
   queue<ll> q;
   map<ll,ll> level;
   vector<ll> bfs(adj.size(),0);
   bfs[id_in]=1;
   q.push(id_in);
   level[id_in]=0;
   ll count=0;
   
   while(q.size()!=0){
     ll x=q.front();
     if(level[x]==4){
       break;
     }
     else{
       ll curr=level[x]+1;
       for(int i=0;i<adj[x].size();i++){
         if(bfs[adj[x][i]]==0){
          bfs[adj[x][i]]=1;
          q.push(adj[x][i]);
          level[adj[x][i]]=curr;
         }
       }

       if(level[x]>1){
        cout<<x<<" ";
        cout<<users[x].getname()<<" ";
        cout<<users[x].getage()<<" ";
        cout<<users[x].getgender()<<endl;
        count++;
       }
       q.pop();
     }
   }
   
   if(count==0){
    cout<<"Try to make friends to display suggestions"<<endl;
   }
   return;
}

void connectafriend(map<ll,User>& users,ll id_in,vector<vector<ll>>& adj){

    suggestions(users,adj,id_in);
    cout<<"Enter the id of the friend to connect"<<endl;
    ll id_fr;
    cin>>id_fr;
    cout<<"Enter his/her name"<<endl;
    string name_fr;
    cin>>name_fr;
    name_fr=lowercase(name_fr);
    
    if(users.find(id_fr)==users.end()){
        cout<<"Incorrect id try again"<<endl;
       return ;
    }
    else if(users[id_fr].getactive()==0){
      cout<<"The user you want to connect is currently inactive"<<endl;
      return ;
    }
    else if(users[id_fr].getname()!=name_fr){
      cout<<"Incorrect name try again"<<endl;
      return ;
    }
    else{
        bool check=true;
        for(int i=0;i<adj[id_in].size();i++){
          if(adj[id_in][i]==id_fr){
            check=false;
          }
        }

      if(check){
          adj[id_in].push_back(id_fr);
        adj[id_fr].push_back(id_in);

        cout<<"You have succesfully connected with a friend";
        
      }
      else{
        cout<<"You are already connected to this person"<<endl;
      }

      
        return ;
    }

}

void removeafriend(map<ll,User>& users,ll id_in,vector<vector<ll>>& adj){
    cout<<"Enter the id of the friend to remove"<<endl;
    ll id_fr;
    cin>>id_fr;
    cout<<"Enter his/her name"<<endl;
    string name_fr;
    cin>>name_fr;
    name_fr=lowercase(name_fr);

    if(users.find(id_fr)==users.end()){
        cout<<"Incorrect id try again"<<endl;
        return ;
    }
    else if(users[id_fr].getname()!=name_fr){
      cout<<"Incorrect name try again"<<endl;
    }
    else{
        for(int i=0;i<adj[id_in].size();i++){
            if(adj[id_in][i]==id_fr){
                adj[id_in].erase(adj[id_in].begin()+i);
                break;
            }
        }

        for(int i=0;i<adj[id_fr].size();i++){
            if(adj[id_fr][i]==id_in){
                adj[id_fr].erase(adj[id_fr].begin()+i);
                break;
            }
        }

        return ;
    }
}






// mutuals
void mutuals(vector<vector<ll>> &adj,map<ll,User>& users,ll id_in,ll id_mut){
    set<ll> st;
    for(int i=0;i<adj[id_mut].size();i++){
      st.insert(adj[id_mut][i]);
    }

    ll count=0;
    cout<<"Mutuals"<<endl;
    for(int i=0;i<adj[id_in].size();i++){
      if(st.find(adj[id_in][i])!=st.end()){
         cout<<adj[id_in][i]<<" ";
         cout<<users[adj[id_in][i]].getname()<<" ";
         cout<<users[adj[id_in][i]].getgender()<<" ";
         cout<<users[adj[id_in][i]].getage()<<endl;
         count++;
      }
    }

    if(count==0){
      cout<<"none"<<endl;
    }
    return;
}

void searchuser(vector<vector<ll>> &adj,map<ll,User> &users,ll id_sr,string name_sr,ll id_in){


   if(users.find(id_sr)==users.end()){
     cout<<"Incorrect id"<<endl;
     return;
   }
   else if(users[id_sr].getactive()==0){
    cout<<"The user you are searching is currently inactive"<<endl;
    return;
   }
   else if(users[id_sr].getname()!=name_sr){
    cout<<"Incorrect name"<<endl;
    return;
   }
   else{
     cout<<users[id_sr].getid()<<" ";
     cout<<users[id_sr].getname()<<" ";
     cout<<users[id_sr].getage()<<" ";
     cout<<users[id_sr].getgender()<<" ";

     if(users[id_sr].getpair_status()){
      cout<<"paired"<<endl;
     }
     else{
      cout<<"single"<<endl;
     }

     mutuals(adj,users,id_in,id_sr);
     return;
   }
}





// delete user
void deleteuser(vector<vector<ll>> &adj,map<ll,User> &users,ll id_de){
    cout<<"Enter your name"<<endl;
    string name_de;
    cin>>name_de;
    name_de=lowercase(name_de);

    cout<<"Enter your password"<<endl;
    string password_de;
    cin>>password_de;

    if(users.find(id_de)==users.end()){
      cout<<"Incorrect Id try again"<<endl;
    }
    else if(users[id_de].getname()!=name_de){
      cout<<"Incorrect name try again"<<endl;
    }
    else if(users[id_de].getpassword()!=password_de){
      cout<<"Incorrect password try again"<<endl;
    }
    else{
      cout<<"Are you sure you want to delete your account"<<endl;
      string conf;
      cin>>conf;
      conf=lowercase(conf);

      if(conf=="yes"){
        users[id_de].active=0;
        cout<<"Your account is successfully deactivated"<<endl;
      }
      else{
        return;
      }
    }
}




// activate user
void activateuser(map<ll,User>& users){
   ll id_act;
   cout<<"Enter your id"<<endl;
   cin>>id_act;

   string password_act;
   cout<<"Enter your password"<<endl;
   cin>>password_act;

   if(users.find(id_act)==users.end()){
    cout<<"Incorrect id"<<endl;
    return;
   }
   else if(users[id_act].password!=password_act){
    cout<<"Incorrect password"<<endl;
    return;
   }
   else if(users[id_act].getactive()==1){
    cout<<"Your account is already activated"<<endl;
    return;
   }
   else{
    users[id_act].active=1;
    cout<<"Your account is succesfully activated"<<endl;
    return;
   }

}




// pairup with someone
void pairup(map<ll,User> &users,ll id_in){
    cout<<"Enter the id of the person to pair"<<endl;
    ll id_pr;
    cin>>id_pr;

    cout<<"Enter his/her name"<<endl;
    string name_pr;
    cin>>name_pr;

    if(users.find(id_pr)==users.end()){
      cout<<"Incorrect id"<<endl;
      return;
    }
    else if(users[id_pr].getname()!=name_pr){
      cout<<"Incorrect name"<<endl;
      return;
    }
    else if(users[id_pr].getactive()==0){
      cout<<"The user is currently inactive"<<endl;
    }
    else if(users[id_pr].getpair_status()==1 || users[id_pr].get_pair()!=-1){
      cout<<"The user is already paired try someother"<<endl;
    }
    else if(users[id_in].getpair_status()==1){
       cout<<"You are already paired ";
       cout<<" or If you made request to pair wait until they send a response to you"<<endl;
    }
    else{
      users[id_in].pair_status=1;
      users[id_pr].pair=id_in;
      cout<<"Your pair request is succesfull, ";
      cout<<"you will be notified everytime you login if you are paired with a person,";
      cout<<" you will not be notified if you get rejected or request is on hold"<<endl;
    }

}



// to remove pair
void removepair(vector<vector<ll>>&adj,map<ll,User>& users,ll id_in){
   cout<<"Enter your partner id"<<endl;
   ll id_pt;
   cin>>id_pt;
   cout<<"Enter your partner name"<<endl;
   string name_pt;
   cin>>name_pt;
   name_pt=lowercase(name_pt);

   if(users.find(id_pt)==users.end()){
    cout<<"Incorrect id of your partner"<<endl;
   }
   else if(users[id_pt].getname()!=name_pt){
    cout<<"Incorrect name of your partner"<<endl;
   }
   else{
    ll partner=users[id_in].get_pair();
    if(partner==-1){
      cout<<"Pair up first to use this option"<<endl;
    }
    else{
      users[id_in].pair=-1;
      users[id_in].pair_status=0;
      users[partner].pair=-1;
      users[partner].pair_status=0;
    }
   }
}






// degree of connection
void degreeofconnection(map<ll,User>& users,vector<vector<ll>> &adj,ll id_in){
   cout<<endl;
   cout<<"Check how closely you are connected to a person and decide whether to pair with them or no"<<endl;
   cout<<endl;
   cout<<"Enter the id of the person you want to check your connection"<<endl;
   ll id_deg;
   cin>>id_deg;
   cout<<"Enter the name of the person "<<endl;
   string name_deg;
   cin>>name_deg;
   name_deg=lowercase(name_deg);

   if(users.find(id_deg)==users.end()){
    cout<<"Incorrect id try again"<<endl;
   }
   else if(users[id_deg].getname()!=name_deg){
    cout<<"Incorrect name try again"<<endl;
   }
   else{
    //  using bfs to identify them; 
    
    ll ans=-1;
    vector<ll> bfs(adj.size(),0);
    queue<ll> q;
    map<ll,ll> level;
    q.push(id_in);
    bfs[id_in]=1;
    level[id_in]=0;
    
    while(q.size()!=0){
      ll x=q.front();
      ll curr=level[x]+1;
      
      if(x==id_deg){
        ans=level[x];
        break;
      }

      for(int i=0;i<adj[x].size();i++){
         if(bfs[adj[x][i]]==0){
          q.push(adj[x][i]);
          bfs[adj[x][i]]=1;
          level[adj[x][i]]=curr;
         }
      }

      q.pop();
    }


    if(ans>5){
      cout<<"Your degree of connection with ";
      cout<<users[id_deg].getname()<<" is ";
      cout<<ans<<" ";
      cout<<"Try a different person with less degree of connection for to pair or make him/her as a friend"<<endl;
    }
    else if(ans==-1){
      cout<<"You need to have some friends before checking this option"<<endl;
    }
    else{
       cout<<"Your degree of connection with ";
      cout<<users[id_deg].getname()<<" is ";
      cout<<ans<<" ";
      cout<<"Try pairing with them or make him/her as a friend for better relation"<<endl;
    }


   }
}






// celebrity ranking
void celebritydashboard(vector<vector<ll>>& adj,map<ll,User>& users){
  cout<<"Check out the most popular users of the app with most connections"<<endl;
  priority_queue<pair<ll,ll>> rank;
  for(int i=0;i<adj.size();i++){
    rank.push({adj[i].size(),i});
  }

  ll k=10;
  ll count=0;
  while(rank.size()!=0 && count<k){
    pair<ll,ll> cele;
    cele=rank.top();
    cout<<"User id:"<<" "<<cele.second<<" ";
    cout<<"name:"<<" "<<users[cele.second].getname()<<" ";
    cout<<"Gender:"<<" "<<users[cele.second].getgender()<<" ";
    cout<<cele.first<<" "<<"connections"<<endl;
    count++;
    rank.pop();
  }

  return;
}













int main(){
      
      map<ll,User> users;
      vector<vector<ll>> adj;
      vector<ll> temp;
      adj.push_back(temp);
      // loading all the users and friends registered
      storeinidata(adj,users);

      cout<<"------------------------------------------------------------------------------------"<<endl;
      cout<<"     ********          Welcome to the Social Friend User App         ********** "<<endl;
      cout<<"------------------------------------------------------------------------------------"<<endl;

    cout<<"1.Create new account"<<endl;
    cout<<"2.Login to your account"<<endl;
    cout<<"3.Activate user account"<<endl;

    int input;
    cin>>input;
    
    bool flag=true;

   if(input==1){
     adduser(adj,users);
   }
   else if(input==2){



    
      // taking user details
          cout<<"Enter your id"<<endl;
          ll id_in;
          cin>>id_in;
          
          cout<<"Enter your password"<<endl;
          string password_in;
          cin>>password_in;

    while(flag){
    if(printuser(password_in,id_in,users)==1){
       
      cout<<endl;
      cout<<"1.Edit user account"<<endl;
      cout<<"2.Search user "<<endl;
      cout<<"3.Delete user account"<<endl;
      cout<<"4.Pair up "<<endl;
      cout<<"5.Degree of connection"<<endl;
      cout<<"6.Celebrity Dashboard"<<endl;
      cout<<"7.Log out"<<endl;
      
      

      ll main;
      cin>>main;
      
     if(main==1){
        
           
          cout<<endl;
          cout<<"1.Edit your name"<<endl;
          cout<<"2.Edit your age"<<endl;
          cout<<"3.Change password"<<endl;
          cout<<"4.Your Friends"<<endl;
          cout<<"5.Connect to a friend"<<endl;
          cout<<"6.Remove a Friend"<<endl;
          cout<<"7.Remove your partner/pair"<<endl;
          cout<<"8.Go to Home"<<endl;

          ll edit;
          cin>>edit;
          if(edit==1){
            changename(users,id_in);
            cout<<"Your Credentials are changed"<<endl;
        
          }
          else if(edit==2){
            changeage(users,id_in);
            cout<<"Your Credentials are changed"<<endl;
          }
          else if(edit==3){
            changepassword(users,id_in);
            cout<<"Your Credentials are changed"<<endl;
        
          }
          else if(edit==4){
             showfriends(users,id_in,adj);
            
          }
          else if(edit==5){
             
              connectafriend(users,id_in,adj);
               
          }
          else if(edit==6){
              
          removeafriend(users,id_in,adj);
              
          }
          else if(edit==7){
             removepair(adj,users,id_in);
          }
          else if(edit==8){
            continue;
          }    
      }
      else if(main==2){
          cout<<"Enter the id of the user to search"<<endl;
          ll id_sr;
          cin>>id_sr;
          cout<<"Enter his/her name"<<endl;
          string name_sr;
          cin>>name_sr;
          name_sr=lowercase(name_sr);

          searchuser(adj,users,id_sr,name_sr,id_in);
      }
      else if(main==3){
         ll id_de;
         cout<<"Enter your id"<<endl;
         cin>>id_de;
        deleteuser(adj,users,id_de);
      }
      else if(main==4){
         pairup(users,id_in);
      }
      else if(main==5){
        degreeofconnection(users,adj,id_in);
      }
      else if(main==6){
        celebritydashboard(adj,users);
      }
      else if(main==7){
        break;
      }
       
      cout<<endl;
      cout<<"Press -1 to exit the app or 1 to return to Homepage"<<endl;
  
        int check;
        cin>>check;
        if(check==1){
            flag=true;
        }
        else{
            flag=false;
        }

        cout<<endl;
    }
    else{
      cout<<"Incorrect details"<<endl;
      cout<<"Press -1 to exit the app or 1 to return to Homepage"<<endl;
  
        int check;
        cin>>check;
        if(check==1){
            flag=true;
        }
        else{
            flag=false;
        }

        cout<<endl;
    }
  
   }

  }
  else{
    activateuser(users);
  }







// writing to a file
exportToFile(users,adj,"data.txt");
  
}