//Structure Prototype
struct Node;


typedef struct Node Node;


//Function Prototypes

Node* createEmptyList();
void insert(Node * head,const int c,const int e);
void insertMiddle(Node * prev,int c, int e);
Node * findPrevious(Node * head,int e);
void deleteList(Node * head);
void putList(Node * head);
Node* addPolynomials(Node * head1,Node * head2);
Node * product(Node * head1,Node * head2);