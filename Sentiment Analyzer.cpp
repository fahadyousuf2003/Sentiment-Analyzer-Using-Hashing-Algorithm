#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<cassert>

using namespace std;
struct node
{
    string words;
    int score;
    node *next;

};
class lists
{
    private:
    node * head;
    node * tail;
    public:
    lists()
    {
        head=NULL;
        tail=NULL;
    }
    void insert(string word1,int score)
    {
        node* temp=new node;
        temp->next=NULL;
        temp->words=word1;
        temp->score=score;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        
        

    }
    node * get_head()
    {
        return head;
    }
    void list_show()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->words<<"  "<<temp->score<<" ";
            temp=temp->next;
        }
    }
    int search_in_list(string word)
    {
        node *temp=this->head;
        while(temp!=NULL)
        {
            if(temp->words==word)
            {
                return temp->score;
            }
            temp=temp->next;
        }
        return 0;
    }

};


// use quadritic collision approach

class hash_table
{
    private:
    lists *obj;
    int size;

    public:
    hash_table(int size)
    {
        this->size=size;
        this->obj=new lists[size];
    }
    int hash_function(string word2)
    {
        int in=0;
        for(int i=0;i<word2.length();i++)
        {
            in=in+int(word2[i]);
        }
        int index=(in) % this->size;
        
        return index;
    }

    void insert_in_table(string word,int score)
    {
        int index=hash_function(word);
        obj[index].insert(word,score);
    }
    void show_tabel()
    {
        node* temp=NULL;
        for(int i=0;i<this->size;i++)
        {
            temp=obj[i].get_head();
            if(temp!=NULL)
            {
                cout<<i<<" ";
                obj[i].list_show();
                cout<<endl;
                temp=NULL;
            }
        }
    }
    int search(string word)
    {
        int index=hash_function(word);
        int check=obj[index].search_in_list(word);
        
        return check;
    }
    
};
using namespace std;

int main()
{
    fstream newfile;
    string row;
    vector<int> score;
    vector<string> word;

    //reading score
    newfile.open("score.csv");
    while(getline(newfile,row)){
        score.push_back(stoi(row));
    }
    newfile.close();

    //reading words
    newfile.open("words.csv");
    while(getline(newfile,row)){
        word.push_back(row);
    }
    newfile.close();


    // hash table object
    hash_table object(score.size());
   



    //creating hash table for words and score
    for(int i=0;i<score.size();i++)
    {
        object.insert_in_table(word[i],score[i]);
    }
    cout<<endl;

    //getting input and seperating words
cout<<"----------------SENTIMENT ANALYZER USING NLP----------------"<<endl;

     cout<<"Enter TEXT :"<<endl<<endl; 
    string input;
    getline(cin,input);
    vector<string> user_data;

   

    string split="";
    for(int i=0;i<input.length()+1;i++){
        char x=input[i];
        if(x ==' '|| x=='\0'){
           
            user_data.push_back(split);
            split="";
        }
        else{
            split=split+x;
        }
    }

    //getting score
    int final_score=0;
    for(int i=0;i<user_data.size();i++)
    {
        int ans=object.search(user_data[i]);

        if(ans!=0){
            final_score=final_score+ans;
        }
        
    }

    float comp=float(float(final_score)/float(user_data.size()));


    cout<<endl<<"Final score is : "<<final_score<<"   Comparitive : "<<comp<<endl<<endl;
    if(comp<0)
        cout<<" Upset !!" << endl << endl;
    else if(comp>0)
        cout<<" Happy !!"<< endl << endl;
    else if(comp==0)
        cout<<" Neutral !!"<< endl << endl;
	
    
}
