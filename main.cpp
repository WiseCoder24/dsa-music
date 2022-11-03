#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    string data;
    Node* next;
    Node(string value){
        data = value;
        next = NULL;
    }
};
vector<string> recents;
vector<string> songQueue;
void addSong(Node* &root, string name){
    Node* n = new Node(name);
    if(root==NULL){
        root = n;
        return;
    }
    Node* temp = root;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    cout<<"Song added"<<endl;
}

void displaySong(Node* root){
    Node* temp = root;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

bool searchSong(Node* root, string song){
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data==song){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void addRecent(string song){
    recents.push_back(song);
}

string showRecent(){
    string song = recents[recents.size()-1];
    recents.pop_back();
    return song;
}

void addInQueue(string song){
    songQueue.push_back(song);
    cout<<"song added in the queue"<<endl;
}

void displayQueue(){
    for(auto i:songQueue){
        cout<<i<<endl;
    }
}

void removeFromQueue(string song){
    vector<string>::iterator it;
    it = remove(songQueue.begin(),songQueue.end(),song);
    vector<string>::iterator it2;
    cout<<"Song removed"<<endl;
}

void playSong(Node* root,string song){
    Node* temp = root;
    if(searchSong(root,song)){
        cout<<"Now playing : "<<song<<endl;
        addRecent(song);
    }
    else{
        cout<<"The song you entered is not in the playlist"<<endl;
    }
}

int main(){
    cout<<"------Welcome to the Music Player------"<<endl;  
    Node* root = NULL;
    addSong(root,"abcd");
    addSong(root,"efgh");
    addSong(root,"manohari");
    addSong(root,"pal");

    displaySong(root);
    if(searchSong(root,"manohari")){
        cout<<"Song is there in the playlist"<<endl;
    }
    else{
        cout<<"Song is not there in the playlist"<<endl;
    }
    
    playSong(root,"manohari");
    playSong(root,"pal");
    cout<<"The recent song is : "<<showRecent()<<endl;
    cout<<"The recent song is : "<<showRecent()<<endl;

    addInQueue("pal");
    addInQueue("manohari");
    addInQueue("abcd");
    displayQueue();
    removeFromQueue("pal");
    displayQueue();
}