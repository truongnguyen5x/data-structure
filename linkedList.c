#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElementType;
struct _PointerType {
    ElementType Inf;
    struct _PointerType *Next;
};
typedef struct _PointerType PointerType;

// prev se tro vao tempNode, tempNode se chua X, tra ve tempNode
PointerType *InsertMiddle(PointerType *Prev, ElementType X) {
    PointerType *TempNode;
    TempNode = (PointerType *)malloc(sizeof(PointerType));
    TempNode->Inf = X;
    TempNode->Next = Prev->Next;
    Prev->Next = TempNode;
    return TempNode;
}
// xoa phan tu phia sau Prev, tra ve data vua bi xoa
ElementType Delete(PointerType *Prev) {
    ElementType X;
    PointerType *TempNode;
    TempNode = Prev->Next;
    Prev->Next = Prev->Next->Next;
    X = TempNode->Inf;
    free(TempNode);
    return X;
}
// chuyen first len head, return gia tri moi
PointerType *InsertToHead(PointerType *First, ElementType X) {
    PointerType *TempNode;
    TempNode = (PointerType *)malloc(sizeof(PointerType));
    TempNode->Inf = X;
    TempNode->Next = First;
    First = TempNode;
    return First;
}
// chen them 1 o vao cuoi, return o first
PointerType *InsertToLast(PointerType *First, ElementType X) {
    PointerType *NewNode;
    PointerType *TempNode;
    NewNode = (PointerType *)malloc(sizeof(PointerType));
    NewNode->Inf = X;
    NewNode->Next = NULL;
    TempNode = First;
    while (TempNode->Next != NULL)
        TempNode = TempNode->Next;
    TempNode->Next = NewNode;
    return First;
}
// xoa nut dau danh sach, return nut thu 2
PointerType *DeleteHead(PointerType *First) {
    PointerType *TempNode;
    TempNode = First->Next;
    free(First);
    return TempNode;
}
// xoa nut cuoi danh sach
PointerType *DeleteLast(PointerType *First) {
    PointerType *Temp1, *Temp2;
    Temp1 = First;
    Temp2 = First;
    while (Temp1->Next != NULL) {
        Temp2 = Temp1;
        Temp1 = Temp1->Next;
    }
    Temp2->Next = NULL;
    free(Temp1);
    return First;
}

int IsEmpty(PointerType *First) { return !First; }

PointerType *MakeNull(PointerType *First) {
    while (!IsEmpty(First))
        First = DeleteHead(First);
    return First;
}

void Print(PointerType *First) {
    PointerType *TempNode;
    printf("\n %ld ", First);
    TempNode = First;
    while (TempNode != NULL) {
        printf("%d:%ld ", TempNode->Inf, TempNode->Next);
        TempNode = TempNode->Next;
    }
    printf("\n");
}

void print2(PointerType *first) {
    printf("\n %ld ", first);
    while (first != NULL) {
        printf("%d:%ld ", first->Inf, first->Next);
        first = first->Next;
    }
    printf("\n");
}

// chua bt

// tao 1 danh sach toan so chan
PointerType *soChan(PointerType *Linp) {
    PointerType *temp, *last, *result;
    last = malloc(sizeof(PointerType));
    temp = Linp; // linp la danh sach nguon
    result = last;
    while (temp != NULL) {
        if ((temp->Inf % 2) != 0) {
            last->Next = malloc(sizeof(PointerType));
            last = last->Next;
            last->Inf = temp->Inf;
            last->Next = NULL;
        }
        temp = temp->Next;
    }
    return result->Next;
    // return result;
}

// dem so chan va le
void OddEven(PointerType *NumList) {
    int soChan = 0, soLe = 0;
    PointerType *temp = NumList;
    while (temp != NULL) {
        if (temp->Inf % 2 == 0) {
            soChan++;
        } else
            soLe++;
        temp = temp->Next;
    }
    printf("so chan la %d va so le: %d", soChan, soLe);
}

// xoa phan tu o vi tri le
PointerType *xoaLe(PointerType *Linp) {
    Linp = Linp->Next;
    PointerType *temp1 = Linp;
    PointerType *temp2 = Linp;
    while ((temp1->Next != NULL) && (temp1->Next->Next != NULL)) {
        temp1->Next = temp1->Next->Next;
        temp1 = temp1->Next;
    }
    temp1->Next = NULL;
    return temp2;
}

// in danh sach dao nguoc
void invert(PointerType *root) {
    if (root == NULL)
        return;
    invert(root->Next);
    printf("%d ", root->Inf);
}

// xoa 1 nut o giua
void deleteMid(PointerType *head, PointerType *input) {
    PointerType *prev = head;
    PointerType *walk = head;
    while (walk != input && walk->Next != NULL) {
        prev = walk;
        walk = walk->Next;
    }
    prev->Next = walk->Next;
}

// xoa 1 nut co Inf= data
void deleteElement(PointerType *head, int input) {
    PointerType *prev = head;
    PointerType *walk = head;
    while (walk->Next != NULL && walk->Inf != input) {
        prev = walk;
        walk = walk->Next;
    }
    if (walk->Inf == input) {
        prev->Next = walk->Next;
    }
}
// noi 2 ds
PointerType *connect(PointerType *a, PointerType *b) {
    PointerType *head = a;
    PointerType *walk = a;
    while (walk->Next != NULL) {
        walk = walk->Next;
    }
    walk->Next = b;
    return a;
}

PointerType *insert(PointerType *first, int k) {
    PointerType *temp = first;
    PointerType *newnode = malloc(sizeof(PointerType));
    newnode->Inf = k;

    if (k < temp->Inf) {
        newnode->Next = temp;
        return newnode;
    } else if (k == temp->Inf) {
        return first;
    } else {
        while (temp->Next != NULL && k >= temp->Next->Inf) {
            temp = temp->Next;
        }
        if (temp->Inf == k) {
            return first;
        } else {
            newnode->Next = temp->Next;
            temp->Next = newnode;
            return first;
        }
    }
}

// Than chuong trinh chinh
int main() {
    PointerType *ds = NULL, *pv = NULL;
    ds = InsertToHead(ds, 15);
    ds = InsertToHead(ds, 6);
    ds = InsertToHead(ds, 5);
    ds = InsertToHead(ds, 3);
    ds = InsertToHead(ds, 2);
	
    // ds = InsertToLast(ds, 24);
    // ds = InsertToLast(ds, 24);
    // ds = InsertToLast(ds, 24);
    // ds = InsertToLast(ds, 13);
    // ds = InsertToLast(ds, 56);
    ds = insert(ds, 6);
    Print(ds);

    return 0;
}
