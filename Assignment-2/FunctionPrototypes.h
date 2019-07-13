//Structure Protoypes
struct List;
struct Student;

//Typedef of structures
typedef struct List List;
typedef struct Student Student;

//Student Functions
Student getStudent();
void putStudent(const Student);


//List Functions
List* CreateList();
int isFull(const List * const);
int isEmpty(const List * const);
void addEnd(List * const,const Student);
void addStart(List * const,const Student);
void addRegno(List * const,const Student,const int);
void searchName(const List * const,char * const);
void deleteRecord(List * const,const int );
void putList(const List * const);
void putPrevNext(const List * const, const int);