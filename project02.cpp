#include <iostream>
#include <string.h>

using namespace std;

typedef struct Word
{
 char Korean[100];
 char English[100];
 struct Word* Next; // ���� Word�� ���� ������
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
 Word* head = new Word; // C��� ������ ���� �޸� �Ҵ�
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
   cout << "���� �޴��Դϴ�." << endl;
  }
 }
}

char MenuWord()
{
 char number;
 cout << "***** ���� ���� *****" << endl;
 cout << "1. �ܾ �߰��ҷ���" << endl;
 cout << "2. �ܾ �����ҷ���" << endl;
 cout << "3. �ܾ �����ҷ���" << endl;
 cout << "4. �ܾ �����ҷ���" << endl;
 cout << "5. �ܾ ã���ּ���" << endl;
 cout << "6. �ܾ �����ּ���" << endl;
 cout << "0. ��������" << endl;
 cout << "*********************" << endl;
 cout << "��ȣ ����: ";
 cin >> number;
 return number;
}

Word* AppendList(Word* p)
{
 cout << "�ѱ��� �Է��ϼ��� : ";
 cin >> p->Korean;
 cout << "��� �Է��ϼ��� : ";
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
 cout << " ��ȣ    �ѱ�    ����  " << endl;
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
  cout << "=> ������ ��ġ�� : ";
  cin >> pos;
 } while (pos<1 || pos>number);

 cout << "�ѱ��� �Է��ϼ��� : ";
 cin >> Korean;
 strcpy(item->Korean, Korean);
 cout << "��� �Է��ϼ��� : ";
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
  cout << "-> ������ ��ȣ�� : ";
  cin >> pos;
 } while (pos<1 || pos>number);

 if (pos == 1)
 {
  cout << "�ѱ��� �Է��ϼ��� : ";
  cin >> Korean;
  strcpy(p->Korean, Korean);
  cout << "��� �Է��ϼ��� : ";
  cin >> English;
  strcpy(p->English, English);
  cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
 }
 else
 {
  int i;
  for (i = 1; i < pos; i++)
  {
   p = p->Next;
  }
  cout << "�ѱ��� �Է��ϼ��� : ";
  cin >> Korean;
  strcpy(p->Korean, Korean);
  cout << "��� �Է��ϼ��� : ";
  cin >> English;
  strcpy(p->English, English);
  cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
  getchar();
 }
}

Word* DeleteList(Word* p)
{
 int pos, number;
 Word* start = p;
 number = DisplayList(p);
 do{
  cout << "-> ������ ��ȣ�� : ";
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
 cout << "ã�� �ܾ� : ";
 cin >> Find;

 while (p->Next != NULL)
 {
  if (strcmp(Find, p->English) == 0 || strcmp(Find, p->Korean) == 0)
  {
   cout << "�ܾ�>> " << p->Korean << " : " << p->English << endl;
   sw = 1;
  }
  p = p->Next;
 }
 if (!sw)
 {
  cout << "�ܾ ã�� ���߽��ϴ�." << endl;
 }
 getchar();
}
