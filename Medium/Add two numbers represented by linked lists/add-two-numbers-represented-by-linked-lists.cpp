//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    void removeleadz(struct Node* &a){
        struct Node* temp = a;
        while(temp and temp->data==0){
            temp=temp->next;
        }
        a = temp;
    }
    void reverse(struct Node *&prev,struct Node *&curr){
        while(curr){
            struct Node *t = curr->next;
            curr->next = prev;
            prev=curr;
            curr=t;
        }
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2){
        removeleadz(num1);
        removeleadz(num2);
        if(!num1 and !num2){
            struct Node* p = new Node(0);
            return p;
        }
        if(!num2){
            return num1;
        }
        if(!num1){
            return num2;
        }
        struct Node* one = NULL;
        reverse(one,num1);
        struct Node* two = NULL;
        reverse(two,num2);
        
        struct Node* x=new Node(-1);
        struct Node* newhead = x;
        int prevcarry = 0;
        while(one and two){
            int sum = one ->data + two->data;
            int sumwithcarry = sum+prevcarry;
            int newcarry = (sumwithcarry)/10;
            int toadd = sumwithcarry%10;
            struct Node* temp=new Node(toadd);
            x->next = temp;
            x=x->next;
            prevcarry = newcarry;
            one = one -> next;
            two = two -> next;
        }
        while(one){
            int sum = one ->data + prevcarry;
            int newcarry = sum/10;
            int toadd = sum%10;
            struct Node* temp=new Node(toadd);
            x->next = temp;
            x=x->next;
            one = one ->next;
            prevcarry = newcarry;
        }
        while(two){
            int sum = two ->data + prevcarry;
            int newcarry = sum/10;
            int toadd = sum%10;
            struct Node* temp=new Node(toadd);
            x->next = temp;
            x=x->next;
            two = two ->next;
            prevcarry = newcarry;
        }
        if(prevcarry){
            struct Node* m = new Node(prevcarry);
            x->next = m;
            x=x->next;
        }
        struct Node* z = NULL;
        reverse(z,newhead->next);
        return z;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends