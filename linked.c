#include "linked.h"

int isEmpty(address p) {
    if (p == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void Ins_Awal(address *p, address PNew) {
    if (PNew == NULL) {
		printf("PNew is NULL\n");
		return;
	}

	(PNew)->next = *p;
	*p = PNew;
}

void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (p->info == nilai) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void InsertAfter(address *pBef, address PNew) {
    if (*pBef != NULL && PNew != NULL) {
        PNew->next = (*pBef)->next;
        (*pBef)->next = PNew;
    }
}

void Del_Awal(address *p, infotype *X) {
    if(*p == NULL){
        printf("Tidak ada yang dapat dihapus\n");
        return;
    }

    address temp = *p;         // Simpan node yang mau dihapus
    *X = temp->info;           // Ambil info-nya
    *p = temp->next;        // Pindahkan head ke node berikutnya
    free(temp);                // Dealokasi node lama
}

void Del_Akhir(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        *X = temp->info;
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *p = NULL;
        }
        free(temp);
    }
}

void Del_After(address *pBef, infotype *X) {
    if (*pBef != NULL && (*pBef)->next != NULL) {
        address temp = (*pBef)->next;
        *X = temp->info;
        (*pBef)->next = temp->next;
        free(temp);
    }
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

int NbElmt(address p) {
    if (p == NULL) return 0;
    return 1 + NbElmt(p->next);
}

infotype Min(address p) {
    if (p == NULL) return -1;
    infotype min = p->info;
    while (p != NULL) {
        if (p->info < min) min = p->info;
        p = p->next;
    }
    return min;
}

infotype Rerata(address p) {
    if (p == NULL) return 0;
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += p->info;
        count++;
        p = p->next;
    }
    return (count == 0) ? 0 : (sum / count);
}

address BalikList(address p) {
    address prev = NULL, curr = p, next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

