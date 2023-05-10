#include <stdio.h>
#include <stdlib.h>

	struct node {
    int data;
    struct node* next;
};

	struct queue {            // Kuyruk yapýsý
    struct node* front;
    struct node* rear;
};

	struct queue* createQueue() {           // Yeni bir kuyruk oluþturma fonksiyonu
    struct queue* h = (struct queue*)malloc(sizeof(struct queue));
    h->front = h->rear = NULL;
    return h;
}


	void enqueue(struct queue* h, int m) {     // Yeni eleman eklemek için fonksiyon
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = h;
    temp->next = NULL;

    if (h->rear == NULL) {
        h->front = h->rear = temp;
        return;
    }

    h->rear->next = temp;
    h->rear = temp;
}


	void dequeue(struct queue* h) {     // Bir elemaný silmek için fonksiyon 
    if (h->front == NULL) {
        printf("Kuyruk bos\n");
        return;
    }

    struct node* temp = h->front;
    h->front = h->front->next;

    if (h->front == NULL) {
        h->rear = NULL;
    }

    free(temp);
}


	void display(struct queue* h) {     // Kuyruktaki tüm elemanlarý yazdýrmak için fonksiyon
    if (h->front == NULL) {
        printf("Kuyruk bos\n");
        return;
    }

    struct node* temp = h->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

	int main() {   
    struct queue* h = createQueue();
    int secim, eleman;

    do {
        printf("\n\n 1-Ekle\n 2-Sil\n 3-Goruntule\n 4-Cikis\n Secim yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklemek istediginiz elemani girin: ");
                scanf("%d", &eleman);
                enqueue(h, eleman);
                break;
            case 2:
                dequeue(h);
                break;
            case 3:
                printf("Kuyruk: ");
                display(h);
                break;
            case 4:
                printf("Programdan cikiliyor.\n");
                break;
            default:
                printf("Gecersiz secim.\n");
        }

    } while (secim != 4);

    return 0;
}
