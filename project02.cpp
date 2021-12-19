#include <iostream>
#include <string.h>

using namespace std;

typedef struct Word
{
 char Korean[100];
 char English[100];
 struct Word* Next; // 다음 Word로 가는 포인터
}Word;

Word* AppendList(Word* p);
Word* InsertList(Word* p);
void UpdateList(Word* p);
Word* DeleteList(Word* p);
void SearchList(Word* p);
int DisplayList(Word* p);
char MenuWord();

int main(void)
{
 Word* head = new Word; // C언어 형식의 동적 메모리 할당
 Word* tail = head;
 head->Next = NULL;

 while(1)
 {
  switch (MenuWord())
  {
  case '1':
   tail = AppendList(tail);
   break;
  case '2':
   head = InsertList(head);
   break;
  case '3':
   UpdateList(head);
   break;
  case '4':
   head = DeleteList(head);
   break;
  case '5':
   SearchList(head);
   break;
  case '6':
   DisplayList(head);
   getchar(); break;
  case '0':
   return 0;
  default:
   cout << "없는 메뉴입니다." << endl;
  }
 }
}

char MenuWord()
{
 char number;
 cout << "***** 영어 사전 *****" << endl;
 cout << "1. 단어를 추가할래요" << endl;
 cout << "2. 단어를 삽입할래요" << endl;
 cout << "3. 단어를 수정할래요" << endl;
 cout << "4. 단어를 삭제할래요" << endl;
 cout << "5. 단어를 찾아주세요" << endl;
 cout << "6. 단어를 보여주세요" << endl;
 cout << "0. 나갈래요" << endl;
 cout << "*********************" << endl;
 cout << "번호 선택: ";
 cin >> number;
 return number;
}

Word* AppendList(Word* p)
{
 cout << "한글을 입력하세요 : ";
 cin >> p->Korean;
 cout << "영어를 입력하세요 : ";
 cin >> p->English;

 p->Next = new Word;
 p = p->Next;
 p->Next = NULL;
 return p;
}

int DisplayList(Word* p)
{
 int i = 1;
 cout << "---------------------" << endl;
 cout << " 번호    한글    영어  " << endl;
 cout << "---------------------" << endl;
 while (p->Next != NULL)
 {
  cout << "  " << i++ << "    " << p->Korean << "    " << p->English << endl;
  p = p->Next;
 }
 cout << "---------------------" << endl;
 return i - 1;
}

Word* InsertList(Word* p)
{
 int pos, number;
 char Korean[100];
 char English[100];
 Word* item;
 Word* start = p;
 item = new Word;
 number = DisplayList(p);

 do{
  cout << "=> 삽입할 위치는 : ";
  cin >> pos;
 } while (pos<1 || pos>number);

 cout << "한글을 입력하세요 : ";
 cin >> Korean;
 strcpy(item->Korean, Korean);
 cout << "영어를 입력하세요 : ";
 cin >> English;
 strcpy(item->English, English);
 
 if (pos == 1)
 {
  item->Next = p;
  start = item;
 }
 else
 {
  int i;
  for (i = 1; i < pos - 1; i++)
  {
   p = p->Next;
  }
  item->Next = p->Next;
  p->Next = item;
 }
 return start;
}

void UpdateList(Word* p)
{
 char Korean[100];
 char English[100];
 int pos, number;
 Word tmp = *p;
 number = DisplayList(p);
 do{
  cout << "-> 수정할 번호는 : ";
  cin >> pos;
 } while (pos<1 || pos>number);

 if (pos == 1)
 {
  cout << "한글을 입력하세요 : ";
  cin >> Korean;
  strcpy(p->Korean, Korean);
  cout << "영어를 입력하세요 : ";
  cin >> English;
  strcpy(p->English, English);
  cout << "변경이 완료되었습니다." << endl;
 }
 else
 {
  int i;
  for (i = 1; i < pos; i++)
  {
   p = p->Next;
  }
  cout << "한글을 입력하세요 : ";
  cin >> Korean;
  strcpy(p->Korean, Korean);
  cout << "영어를 입력하세요 : ";
  cin >> English;
  strcpy(p->English, English);
  cout << "변경이 완료되었습니다" << endl;
  getchar();
 }
}

Word* DeleteList(Word* p)
{
 int pos, number;
 Word* start = p;
 number = DisplayList(p);
 do{
  cout << "-> 삭제할 번호는 : ";
  cin >> pos;
 } while (pos<1 || pos>number);

 if (pos == 1)
 {
  start = p->Next;
 }
 else
 {
  int i;
  Word* tmp;
  for (i = 1; i < pos - 1; i++)
  {
   p = p->Next;
  }
  tmp = p->Next;
  p->Next = p->Next->Next;
 }
 return start;
}

void SearchList(Word* p)
{
 char Find[100];
 int sw = 0;
 cout << "찾을 단어 : ";
 cin >> Find;

 while (p->Next != NULL)
 {
  if (strcmp(Find, p->English) == 0 || strcmp(Find, p->Korean) == 0)
  {
   cout << "단어>> " << p->Korean << " : " << p->English << endl;
   sw = 1;
  }
  p = p->Next;
 }
 if (!sw)
 {
  cout << "단어를 찾지 못했습니다." << endl;
 }
 getchar();
}
