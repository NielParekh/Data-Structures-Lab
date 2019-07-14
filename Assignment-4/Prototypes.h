struct Node;
struct Student;

typedef struct Node Node;
typedef struct Student Student;

//Doubly Linked List functions
Node* createEmptyList();
void addFirst(Node*,Node*,const Student S);
void addLast(Node*,Node*,const Student S);
Node* findRecord(Node*,Node*,char * const);
void addName(Node*,const Student S);
void putList(Node*,Node*);
void putListSorted(Node*,Node*);
void deleteRecord(Node*);


//Student Functions
Student getStudent();
void putStudent(const Student);
