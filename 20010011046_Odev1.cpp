//Abdullah Dedeoðlu 20010011046
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	char isim[20];
	char soyisim[20];
	long long int numara;
	struct node* next;
};
struct node * root = NULL;

node * ekle(node* root, char Ad[], char Soyad[],long long int Num){
	//struct node* newnode; bu fonksiyona her girdiðinde NULL olmicaðý için her giriste bos yere bellekte node olusturma.
	//Nulla girince olustur.  
	node * iter = root;
	
	if (root==NULL){
		
		root = (node*)malloc(sizeof(node));
		strcpy(root->isim,Ad);
		strcpy(root->soyisim,Soyad);
		root->numara = Num;
		root->next = root;
		//root=newnode;	 rootu burda root demene gerek yok. mainde root = ekle() dediðin için return etsen en son o zaten root olarak alýcak
		return root;
	}
	else {
		while (iter->next!=root){
			//numara listede varsa eklemeyi iptal et 
			if (iter->numara == Num)
				return root;
				
			iter=iter->next;
		}
		
		node * newnode=(node*)malloc(sizeof(node));
		strcpy(newnode->isim,Ad);
		strcpy(newnode->soyisim,Soyad);
		newnode->numara = Num;
		iter->next = newnode;
		newnode->next = root;
		root=newnode;
		return root; 	
		
	}

	
}

void ara(node * root){	
	int sec, a;
	long long int numara;
	char ad[20];
	node* iter;
	iter=root;
	printf("ada gore arama=>1\n");
	printf("Telefon numarasina gore arama=>2\n");
	printf("=> ");
	scanf("%d", &sec);
	if (sec==1){
		printf("Aranacak kisinin adini giriniz: ");
		scanf("%s", ad);
		a=1;
		if(strcmp(ad, iter->isim)==0 && (iter->next==iter)){
			printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
			a=2;
		}
		while(iter->next!=root){
			if(strcmp(ad, iter->isim)==0){
				printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
				a=2;
			}
			iter=iter->next;						
		}
		if(strcmp(ad, iter->isim)==0 && (iter->next==root)){
			printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
			a=2;
		}
		if(a==1){
			printf("Boyle bir kisi bulunmamaktadir.\n");
			}		
	}
	else {
		printf("Aranacak kisinin numarasini giriniz: ");
		scanf("%lld", &numara);
		a=1;
		if((iter->numara==numara) && (iter->next==iter)){
			printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
			a=2;
		}
		while(iter->next!=root){
			if(iter->numara==numara){
				printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
				a=2;
			}
			iter=iter->next;						
		}
		if((iter->numara==numara) && (iter->next==root)){
			printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
			a=2;
		}
		if(a==1){
			printf("Boyle bir kisi bulunmamaktadir.\n");
			}
	
		}
}
void listele(node * root){	
	
	if(root == NULL) // listelenmesi istenen liste bos ise listelemeye gerek yok.
		return;
	
	if(root->next == root){
		printf("%s %s %lld\n",root->isim, root->soyisim, root->numara);	
		return;
	}
	
	node * iter = root;
	
	while(iter->next != root){
		
	printf("%s %s %lld\n",iter->isim, iter->soyisim, iter->numara);
	iter = iter->next;
	}
	
	//son eleman
	printf("%s %s %lld\n\n",iter->isim, iter->soyisim, iter->numara); //
	
}


node * sirala(node * root){
	int degisen=0; 
    struct node * iter; 
    struct node * iter2;
	struct node * temp; 
	iter2->next=iter;
  	printf("kontrol4");
    if (root == NULL) 
        return NULL; 
    iter=root;
    while (iter->next != root) 
        { 
            if (strcmp(iter->soyisim, iter->next->soyisim)>0) 
            { 
                temp = iter; 
    			iter = iter->next; 
    			iter->next = temp;
    			degisen=1;
            } 
            iter=iter->next;
            iter2=iter2->next;
        }
    
    if(degisen==1){
    	printf("kontrol3");
    	while(degisen==1){
    		iter = root;
    		while (iter->next != root) { 
    			degisen=0;
            	if (strcmp(iter->soyisim, iter->next->soyisim)>0){ 
                	temp = iter; 
    				iter = iter->next; 
    				iter->next = temp;
    				degisen=1;
    				
            }
			iter=iter->next;
        	} 
		}
	}
	printf("kontrol2");
	listele(root); 
	return root;
  
    
}
	

node * sil(node * root, long long int num){
	node * iter;
	node * oncuiter;
	node * temp;
	iter=root;
	oncuiter->next=iter;
	
	//liste bossa
	if(root == NULL) 
		return NULL;
		
	//Tek eleman varsa onu siler
	if((num==iter->numara)&&(iter->next==iter)){
		root=NULL;
		free(iter);
		return NULL;
	}
	//Bastaki elemani siliyor
	if(root->numara==num){
			while(iter->next!=root){
				iter=iter->next;
			}			
			temp=iter->next;
			iter->next=temp->next;
			root=iter->next;
			free(temp);
			return root;				
	}
	//Normal silme
	while (iter->next!=root){
		oncuiter->next=iter;
		if (num==iter->numara){	
			temp=iter;
			oncuiter->next=temp->next;
			iter=iter->next;
			free(temp);
		}
		iter=iter->next;
		oncuiter=oncuiter->next;		
	}
	if((iter->numara==num) && (iter->next==root)){			
		temp=iter;
		oncuiter->next=temp->next;
		free(temp);
	}
	return root;
}


int main(){
	int secim;
    node * root = NULL;
    
    while(1){
    	
    	printf("1.Ekleme\n2.Arama\n3.Listeleme\n4.Siralama\n5.Silme\n");
		printf("Yapmak istediginiz islemi giriniz: ");
    	scanf("%d", &secim);
	    
		switch(secim)
	        {
	            case 1:
	            	char isim[20],soyisim[20];
	            	long long int numara;
	            	
	            	printf("Eklemek istediginiz kisinin ismi: ");
					scanf("%s", &isim);
					
					printf("Eklemek istediginiz kisinin soyismi: ");
					scanf("%s", &soyisim);
					
					printf("Eklemek istediginiz kisinin numarasi: ");
					scanf("%lld", &numara);
					
					root = ekle(root,isim,soyisim,numara);
					
	            	break;
	            case 2:
					ara(root);
	            	break;
	            case 3:
	            	printf("\n");
					listele(root);
	            	break;
	            case 4:
					root=sirala(root);
					printf("kontrol1");
	            	break;
	            case 5:
	            	long long int num;
					printf("Silinmesini istediginiz kisinin numarasini giriniz:");
					scanf("%lld", &numara);
					root = sil(root, numara);
	            	break;
	            /*case 6:sort();
	            break;*/
	            
	        }
		}
}
