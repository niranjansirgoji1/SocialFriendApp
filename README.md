# Social Friend User App 

Social Friend User App is a  C++ application that simulates a simplified social networking system. Users can register, log in, add friends, view mutual connections, and even send pair-up (relationship) requests. The app models users as nodes in a graph and utilizes core algorithms like BFS for friend suggestions and shortest connection paths. With features like friend dashboards, activation controls, and persistent file storage, it showcases a real-world application of data structures and algorithms in C++.

## App Features

### User Features
- **Creating user accounts/login**: Users can create new accounts and login if they have an existing account 
  ![Login](Screenshots/Loginorcreateaccount.png)
- **Edit user account/age/name/password etc**: Users can edit their details 
   ![Edit](Screenshots/Edit.png)
- **Delete/Deactivate your account**:Users can delete/deactivate their account also can reactivate their account
   ![Deleteaccount](Screenshots/Deactivate.png)
### Friend System

- **Connecting with friends/users**:Users can connect with various users and make them as friends
    ![Connect](Screenshots/Connect.png)
- **Block/remove friends**:Users can block other users from connecting with them
- **Search user/view Mutuals**:Users can search any user/view their friends.
   ![Mutuals](Screenshots/Mutuals.png)
- **Friend suggestions**:Users get friend suggestions when they try to connect with any friend.
   ![Suggestions](Screenshots/Suggestions.png)
### Pair up option

- **Send pair request to opposite gender**:User can pair up with their opposite gender and can requests to them to pair up
    ![Pairup](Screenshots/Pairup.png)
- **Accept or reject pair request**:Users can either reject or accept pair requests from other users.
    ![Accept](Screenshots/Acceptpairup.png)
- **Remove pair connection**:Users can remove their current pair connection and then can pair up with someother

### Other Top Features

- **Celebrity Dashboard**:Users can view the top most users of the app with most friends/connections
   ![Celebrityranking](Screenshots/Celebrityranking.png)
- **Degree of Connection**:The top most feature of this app where user can check how closely they are connected to an user.
   ![DegreeofConnection](Screenshots/Degreeofconnection.png)

## Concepts used

### Data Structures and Algorithms

- **Graphs and Graphs algorithms**:Users and their connections are stored using graphs and graph algorithms like bfs are used for "Degree of connection","Suggestions","Mutuals"etc.

- **Vectors,maps**:Hash map is used to keep track of the userids etc.

- **Queues,Priority Queue**: Priority queue used for celebrity dashboard rankings

- **OOPS**:A Class named User is defined to store the data of the users 

- **File I/O**:file i/o concepts are used to store the user data.

## Getting started

### Prerequisites
- C++
- Data Structures and Algorithms

## How to run

- Clone the repository
- use g++ compiler to compile the main.cpp file
- run the program





