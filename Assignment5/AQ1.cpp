/ #include<iostream>
// using namespace std;
// //Menu driven program for linked list
// struct Node{
//     int data;
//     Node* next;
// };
// class SinglyLinkedList{
// private:
//      Node* head;
// public:
//     SinglyLinkedList(){
//         head =NULL;

//     }
//     void insertAtBegining(int value){
//         Node* newnode =new Node();
//         newnode->data=value;
//         newnode->next=head;
//         head=newnode;
//         cout<<"Node inserted at begining"<<endl;
//     }
//     void insertAtEnd(int value){
//         Node* newnode =new Node();
//         newnode->data=value;
//         newnode->next=NULL;
//         if(head==NULL){
//             head=newnode;
//             return;
//         }
//         Node* temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=newnode;
//         cout<<"Node inserted at end"<<endl;
//     }
//     void insertBefore(int target,int value){
//         if(head==NULL){
//             cout<<"List is empty"<<endl;
//             return;
//         }
//         if(head->data==target){
//             insertAtBegining(value);
//             return;
//         }
//         Node* temp=head;
//         while(temp->next!=NULL && temp->next->data!=target){
//             temp=temp->next;
//         }
//         if(temp->next==NULL){
//             cout<<"Target not found"<<endl;
//             return;
//         }
        
//         Node* newnode=new Node();
//         newnode->data=value;
//         newnode->next=temp->next;
//         temp->next=newnode;
//         cout<<"Node inserted before "<<target<<endl;
//     }
//     void insertAfter(int target,int value){
//         if(head==NULL){
//             cout<<"List is empty"<<endl;
//             return;
//         }
//         Node* temp=head;
//         while(temp!=NULL && temp->data!=target){
//             temp=temp->next;
//         }
//         if(temp==NULL){
//             cout<<"Target not found"<<endl;
//             return;
//         }
        
//         Node* newnode=new Node();
//         newnode->data=value;
//         newnode->next=temp->next;
//         temp->next=newnode;
//         cout<<"Node inserted after "<<target<<endl;
//     }
//     void deleteAtBegining(){
//         if(head==NULL){
//             cout<<"List is Empty"<<endl;
//             return;
//         }
//         Node* temp=head;
//         head=head->next;
//         delete temp;
//         cout<<"Node deleted at begining"<<endl;
//     }
//     void deleteAtEnd(){
//         if(head==NULL){
//             cout<<"List is Empty"<<endl;
//             return;
//         }
//         if(head->next==NULL){
//             delete head;
//             head=NULL;
//             cout<<"Node deleted at end"<<endl;
//             return;
//         }
//         Node* temp=head;
//         while(temp->next->next!=NULL){
//             temp=temp->next;
//         }
//         delete temp->next;
//         temp->next=NULL;
//         cout<<"Node deleted at end"<<endl;
//     }
//     void deleteNode(int target){
//         if(head==NULL){
//             cout<<"List is Empty"<<endl;
//             return;
//         }
//         if(head->data==target){
//             deleteAtBegining();
//             return;
//         }
//         Node* temp=head;
//         while(temp->next!=NULL && temp->next->data!=target){
//             temp=temp->next;
//         }
//         if(temp->next==NULL){
//             cout<<"Target not found"<<endl;
//             return;
//         }
//         Node* delNode=temp->next;
//         temp->next=temp->next->next;
//         delete delNode;
//         cout<<"Node with value "<<target<<" deleted"<<endl;
//     }
//     void searchNode(int target){
//         if(head==NULL){
//             cout<<"List is Empty"<<endl;
//             return;
//         }
//         Node* temp=head;
//         int position=0;
//         while(temp!=NULL){
//             if(temp->data==target){
//                 cout<<"Node found at position "<<position<<endl;
//                 return;
            
//             }
//             temp=temp->next;
//             position++;
//         }
//         cout<<"Node not found"<<endl;
//     }
//     void display(){
//         if(head==NULL){
//             cout<<"List is Empty"<<endl;
//             return;
//         }
//         Node* temp=head;
//         cout<<"List elements: ";
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }

// };
// int main(){
//     SinglyLinkedList sll;
//     int choice,value,target;
//     while(true){
//         cout<<"\n--- Menu ---\n";
//         cout<<"1. Insert at Beginning\n";
//         cout<<"2. Insert at End\n";
//         cout<<"3. Insert Before a Given Node\n";
//         cout<<"4. Insert After a Given Node\n";
//         cout<<"5. Delete at Beginning\n";
//         cout<<"6. Delete at End\n";
//         cout<<"7. Delete a Given Node\n";
//         cout<<"8. Search a Node\n";
//         cout<<"9. Display List\n";
//         cout<<"10. Exit\n";
//         cout<<"Enter your choice: ";
//         cin>>choice;
//         switch(choice){
//             case 1:
//                 cout<<"Enter value to insert: ";
//                 cin>>value;
//                 sll.insertAtBegining(value);
//                 break;
//             case 2:
//                 cout<<"Enter value to insert: ";
//                 cin>>value;
//                 sll.insertAtEnd(value);
//                 break;
//             case 3:
//                 cout<<"Enter target node value: ";
//                 cin>>target;
//                 cout<<"Enter value to insert: ";
//                 cin>>value;
//                 sll.insertBefore(target,value);
//                 break;
//             case 4:
//                 cout<<"Enter target node value: ";
//                 cin>>target;
//                 cout<<"Enter value to insert: ";
//                 cin>>value;
//                 sll.insertAfter(target,value);
//                 break;
//             case 5:
//                 sll.deleteAtBegining();
//                 break;
//             case 6:
//                 sll.deleteAtEnd();
//                 break;
//             case 7:
//                 cout<<"Enter node value to delete: ";
//                 cin>>target;
//                 sll.deleteNode(target);
//                 break;
//             case 8:
//                 cout<<"Enter node value to search: ";
//                 cin>>target;
//                 sll.searchNode(target);
//                 break;
//             case 9:
//                 sll.display();
//                 break;
//             case 10:
//                 cout<<"Exiting..."<<endl;
//                 return 0;
//             default:
//                 cout<<"Invalid choice! Please try again."<<endl;
//         }
//     }
//     return 0;
// }



