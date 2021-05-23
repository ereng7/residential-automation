#include<stdio.h>
#include<string.h>
#include <locale.h>
#include <ctype.h>
#include<stdlib.h>
//Marmara �niversitesi Teknoloji Fak�ltesi Bilgisayar M�hendisli�i
//Ahmet Faruk Alkan     :170420044
//Mustafa Eren G�lbahar :170420019
//�smail Can Varl�      :171420004
//c olarak �al��t�r
struct konut {

	int konutno;
	int konutalani;
	int konutkat;
	char konutdurum[10];
	int konutfiyat;
	char arsabilgisi[10];
	char ilbilgisi[15];
	char ilcebilgisi[15];
	char odasayisi[10];

} def={0,0,0,"\0",0,"\0","\0","\0","\0"};


struct konut kon[501];

void konutgoruntule();
void konutekle();
struct konut sil ();
int konutkaydir();
void konutduzenle();
void guncelle();
void txtoku();
void txtyaz();
void filtre();
void fiyatfiltre();
void katfiltre();
void mkarefiltre();
void arsdurfiltre();
void arsbilfiltre();
void konumbilfiltre();
void kondurfiltre();
void odasayfiltre();
void cokfiltreleme();
FILE *dosya;

int main () {
	setlocale(LC_ALL, "Turkish");
	int i,secim,silno,ilk=1;
	system("COLOR F2");

	txtoku();

	do {

	system("COLOR F2");
	printf("\n\t\t               <><><><><>                 \n");
	printf("\t\t           <><><><><><><><><>            \n");
	printf("\t\t        <><><><><><><><><><><><><>        \n");
	printf("\t\t    <><><><><><><><><><><><><><><><><>    \n");
	printf("\t\t<><><><><><><><><><><><><><><><><><><><><>\n");
	printf("\t\t**  Konutlar� g�r�ntelemek i�in  : 1    **\n");
	printf("\t\t**  Konut eklemek i�in           : 2    **\n");
	printf("\t\t**  Konut silmek i�in            : 3    **\n");
	printf("\t\t**  G�ncellemek i�in             : 4    **\n");
	printf("\t\t**  Filtrelemek i�in             : 5    **\n");
	printf("\t\t**  ��k�� yapmak i�in            : 0    **\n");
	printf("\t\t**  ----------------------------------  **\n");
	printf("\t\t    Se�iminiz : ")	;
    scanf("%d",&secim);
	printf("\t\t<><><><><><><><><><><><><><><><><><><><><>\n\n\n");
	if(secim==1){
		konutgoruntule();
	}
	if(secim==2){
		konutekle();
	}
	if(secim==3){
		konutgoruntule(secim);
		printf("Kac numarali konutu silmek istiyorsunuz ?(Geri donmek icin 0 giriniz)\nSecim : ");
	    scanf("%d",&silno);
	   	while(!(silno<=500)||!(silno>=0)){
			printf("!!HATA!!\n");
			printf("Kac numarali konutu sileceksiniz ? \nSecim : ");
			scanf("%d",&silno);
			if(silno==0)
				break;
    	 }
		kon[silno-1]=sil();
			
		getch();
		system("CLS");
	}

	konutduzenle();
	txtyaz();

	if(secim==4){
		guncelle();
	}
	if(secim==5){
		filtre();
	}
	if(secim!=1&&secim!=2&&secim!=3&&secim!=4&&secim!=5&&secim!=0){
		printf("\t\t    Yanlis Secim ")	;
	}
	system("CLS");


	}while(secim!=0);





	return 0 ;
}


void konutgoruntule(int secim){
	setlocale(LC_ALL, "Turkish");
	int i ;
	system("CLS");
	system("COLOR e1");


    if(!strcmp(kon[0].ilbilgisi,"\0"))   
		printf("\t\t<<Kayit bulunamadi>>\n");
	else{
	printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");
	for(i=0;i<500;i++){
		
         if(strcmp(kon[i].ilbilgisi,"\0")){
	    	printf("%d\t",i+1);
			printf("%d\t",kon[i].konutalani);
			printf("%d\t",kon[i].konutkat);
			printf("%d\t\t",kon[i].konutfiyat);
			printf("%s\t\t  ",kon[i].konutdurum);
			printf("%s    ",kon[i].arsabilgisi);
			printf("%s/",kon[i].ilbilgisi);
			printf("%s\t  ",kon[i].ilcebilgisi);
			printf("%s\n",kon[i].odasayisi);

		}

	}
	}

	if(secim!=3){
		getch();
		system("CLS");
	}

}


void konutekle(){
	setlocale(LC_ALL, "Turkish");
	system("CLS");
	system("COLOR C7");

	int kac,i,kac1;
	printf("\t!! Turk�e Karaker Girmeyiniz!!\n");
	
	printf("\tKac tane konut gireceksiniz : ");
		scanf("%d",&kac);
		kac1=0;
	while(!(kac<=10)||!(kac>=0)){
		printf("\t!!HATA!!\n");
		printf("\tKac tane konut gireceksiniz : ");
		scanf("%d",&kac);
     }		
	if(kac!=0){
		
		for(i=0;i<500;i++){
		if(!strcmp(kon[i].ilbilgisi,"\0")){
			printf("\n----------------------------------------------\n");
			kon[i].konutno=i;
			printf("\tKonut alani(m�) : ");
			scanf("%d",&kon[i].konutalani);
			printf("\tKonut kat bilgisi : ");
			scanf("%d",&kon[i].konutkat);
			getchar();
			printf("\tKonut durum(Satilik/Kira) : ");
			gets(kon[i].konutdurum);strcpy(kon[i].konutdurum,strupr(kon[i].konutdurum));
			printf("\tKonut fiyat : ");
			scanf("%d",&kon[i].konutfiyat);
			getchar();
			printf("\tKonut arsa bilgisi(Apartman/Dukkan/Mustakil) : ");
			gets(kon[i].arsabilgisi);strcpy(kon[i].arsabilgisi,strupr(kon[i].arsabilgisi));
			printf("\tKonut il bilgisi : ");
			gets(kon[i].ilbilgisi);strcpy(kon[i].ilbilgisi,strupr(kon[i].ilbilgisi));
			printf("\tKonut ilce bilgisi : ");
			gets(kon[i].ilcebilgisi);strcpy(kon[i].ilcebilgisi,strupr(kon[i].ilcebilgisi));
			printf("\tKonut oda bilgisi(Oda+salon) : ");
			gets(kon[i].odasayisi);
			printf("\n----------------------------------------------\n");
			kac1++;
			if(kac==kac1)
			break;
			}
		}
	}
	getch();
	system("CLS");
}

struct konut sil () {
	struct konut kon;

	kon.konutalani=0;
	kon.konutkat=0;
	kon.konutfiyat=0;
	strcpy(kon.konutdurum,"\0");
	strcpy(kon.arsabilgisi,"\0");
	strcpy(kon.ilbilgisi,"\0");
	strcpy(kon.ilcebilgisi,"\0");
	strcpy(kon.odasayisi,"\0");

	return kon;
}

int konutkaydir(){

	int i,no=9999;
	for(i=1;i<500;i++){
		if(strcmp(kon[i].ilbilgisi,"\0")&&!strcmp(kon[i-1].ilbilgisi,"\0")){
			no=i;
		}

	}
	return no;

}
void konutduzenle(){
	int i;
	if(konutkaydir(kon)<500){
		i=konutkaydir(kon);
		kon[konutkaydir(kon)-1]=kon[konutkaydir(kon)];
		kon[i]=sil();
	}

}
void guncelle(){
	setlocale(LC_ALL, "Turkish");

	system("CLS");
	int i;
	konutgoruntule(3);
	printf("Kac numarali konutu g�ncelleyeceksin(Geri donmek icin 0 giriniz) : ");
	scanf("%d",&i);
	while(!(i<=500)||!(i>=0)){
	printf("!!HATA!!\n");
	printf("Kac numarali konutu g�ncelleyeceksin ? \nSecim : ");
	scanf("%d",&i);}
	if(i!=0){	

	printf("\n----------------------------------------------\n");
	printf("\tKonut alani(m�) : ");
	scanf("%d",&kon[i-1].konutalani);
	printf("\tKonut kat bilgisi : ");
	scanf("%d",&kon[i-1].konutkat);
	getchar();
	printf("\tKonut durum(Satilik/Kira) : ");
	gets(kon[i-1].konutdurum);
	printf("\tKonut fiyat : ");
	scanf("%d",&kon[i-1].konutfiyat);
	getchar();
	printf("\tKonut arsa bilgisi(Apartman/Dukkan/M�stakil) : ");
	gets(kon[i-1].arsabilgisi);
	printf("\tKonut il bilgisi : ");
	gets(kon[i-1].ilbilgisi);
	printf("\tKonut ilce bilgisi : ");
	gets(kon[i-1].ilcebilgisi);
	printf("\tKonut oda bilgisi(Oda+salon) : ");
	gets(kon[i-1].odasayisi);
	printf("\n----------------------------------------------\n");
	}
			
    
	getch();
	system("CLS");
}
void txtoku(){
	int i=0;

	if((dosya=fopen("KONUT.txt","r"))!=NULL){
		while(!feof(dosya)){
			for(i=0;i<500;i++){
				if(!strcmp(kon[i].ilbilgisi,"\0"))
				fscanf(dosya,"%d %d %d %d %s %s %s %s %s",&kon[i].konutno-1,&kon[i].konutalani,&kon[i].konutkat,&kon[i].konutfiyat,&kon[i].konutdurum,&kon[i].arsabilgisi,&kon[i].ilbilgisi,&kon[i].ilcebilgisi,&kon[i].odasayisi);
				
			}

		}

	}
	else{
		printf("\t\t\t  <<Dosya Bulunamadi>>");
	}
	fclose(dosya);

}
void txtyaz(){
	int i ;
	dosya=fopen("KONUT.txt","w");

	for(i=0;i<500;i++){
	    if(strcmp(kon[i].ilbilgisi,"\0")){

	    	fprintf(dosya,"%d\t",i);
			fprintf(dosya,"%d\t",kon[i].konutalani);
			fprintf(dosya,"%d\t",kon[i].konutkat);
			fprintf(dosya,"%d\t\t",kon[i].konutfiyat);
			fprintf(dosya,"%s\t\t  ",strupr(kon[i].konutdurum));
			fprintf(dosya,"%s    ",strupr(kon[i].arsabilgisi));
			fprintf(dosya,"%s ",strupr(kon[i].ilbilgisi));
			fprintf(dosya,"%s\t  ",strupr(kon[i].ilcebilgisi));
			fprintf(dosya,"%s\n",strupr(kon[i].odasayisi));

		}

	}fclose(dosya);
}
void filtre(){
	int secim;
	system("COLOR f2");
	system("CLS");
	do{
	printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
	printf("\t\t**  Coklu filtreleme icin                       : 1    **\n");
	printf("\t\t**  Fiyat filterelemesi icin                    : 2    **\n");
	printf("\t\t**  Kat bilgisi filtrelemesi icin               : 3    **\n");
	printf("\t\t**  m� bilgisi filtrelemesi icin                : 4    **\n");
	printf("\t\t**  Arsa durumu filtrelemsi icin (Satilik-Kira) : 5    **\n");
	printf("\t\t**  Arsa bilgisi filtrelemsi icin               : 6    **\n");
	printf("\t\t**  Konum bilgisi filtrelemsi icin              : 7    **\n");
	printf("\t\t**  Oda sayisi filtrelemsi icin                 : 8    **\n");
	printf("\t\t**  Cikis yapmak icin                           : 0    **\n");
	printf("\t\t**  -------------------------------------------------  **\n");
	printf("\t\t    Seciminiz : ")	;
    scanf("%d",&secim);
	printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

	if(secim==1){
		cokfiltreleme();
	}
	if(secim==2){
		fiyatfiltre();
	}

	if(secim==3){
		katfiltre();
	}
	if(secim==4){
		mkarefiltre();
	}
	if(secim==5){
		arsdurfiltre();
	}
	if(secim==6){
		arsbilfiltre();
	}
	if(secim==7){
		konumbilfiltre();
	}
	if(secim==8){
		odasayfiltre();
	}

	if(secim!=1&&secim!=2&&secim!=3&&secim!=4&&secim!=5&&secim!=6&&secim!=7&&secim!=8&&secim!=0){
		printf("\t\t\t  404--Yanlis tus--404\n");
		printf("\t\t    Seciminiz : ")	;
    	scanf("%d",&secim);
	}
	system("CLS");
	}while(secim!=0);
	
	
}
void fiyatfiltre(){
	int i,j,gecicii,gecicid,dolu=0,minimum,maksimum;
	int dizi[500][2];

	for(i=0;i<500;i++)
    {
		dizi[i][0]=i;
		dizi[i][1]=kon[i].konutfiyat;
		if(strcmp(kon[i].ilbilgisi,"\0"))
		dolu++;
	}

    system("CLS");
	int secim;

	do{
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("\t\t |  Fiyatlari artan sira ile goruntule  : 1   |\n");
		printf("\t\t |  Fiyatlari azalan sira ile goruntule : 2   |\n");
		printf("\t\t |  Fiyat araligi belirle               : 3   |\n");
		printf("\t\t |  Cikmak icin                         : 0   |\n");
		printf("\t\t |  ----------------------------------------- |\n");
		printf("\t\t    Seciminiz : ")	;
 	    scanf("%d",&secim);
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

		if(secim==1)
        {
            for(i=0;i<dolu;i++)
            {
                for(j=i;j<dolu;j++)
                {
                    if(dizi[i][1]>dizi[j][1])
                    {
                    	gecicii=dizi[i][0];         gecicid=dizi[i][1];
                    	dizi[i][0]=dizi[j][0];      dizi[i][1]=dizi[j][1];
                    	dizi[j][0]=gecicii;         dizi[j][1]=gecicid;
                    }
                }
           }

			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)

            {
            if(strcmp(kon[dizi[i][0]].ilbilgisi,"\0")){
            	printf("%d\t",i+1);
				printf("%d\t",kon[dizi[i][0]].konutalani);
				printf("%d\t",kon[dizi[i][0]].konutkat);
				printf("%d\t\t",kon[dizi[i][0]].konutfiyat);
				printf("%s\t\t  ",kon[dizi[i][0]].konutdurum);
				printf("%s    ",kon[dizi[i][0]].arsabilgisi);
				printf("%s/",kon[dizi[i][0]].ilbilgisi);
				printf("%s\t  ",kon[dizi[i][0]].ilcebilgisi);
				printf("%s\n",kon[dizi[i][0]].odasayisi);
			}

            }
		}

		if(secim==2)
        {
            for(i=0;i<dolu;i++)
            {
                for(j=i;j<dolu;j++)
                {
                    if(dizi[i][1]<dizi[j][1])
                    {
                    	gecicii=dizi[i][0];         gecicid=dizi[i][1];
                    	dizi[i][0]=dizi[j][0];      dizi[i][1]=dizi[j][1];
                    	dizi[j][0]=gecicii;         dizi[j][1]=gecicid;
                    }
                }
           }

			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)

            {
            if(strcmp(kon[dizi[i][0]].ilbilgisi,"\0")){
            	printf("%d\t",i+1);
				printf("%d\t",kon[dizi[i][0]].konutalani);
				printf("%d\t",kon[dizi[i][0]].konutkat);
				printf("%d\t\t",kon[dizi[i][0]].konutfiyat);
				printf("%s\t\t  ",kon[dizi[i][0]].konutdurum);
				printf("%s    ",kon[dizi[i][0]].arsabilgisi);
				printf("%s/",kon[dizi[i][0]].ilbilgisi);
				printf("%s\t  ",kon[dizi[i][0]].ilcebilgisi);
				printf("%s\n",kon[dizi[i][0]].odasayisi);
			}

            }
		}

		if(secim==3)
        {
            printf("\nFiyat araligi ne olsun ?");
            printf("\nMinimum fiyat : ");
            scanf("%d",&minimum);
            printf("Maksimum fiyat : ");
            scanf("%d",&maksimum);
            while(maksimum<minimum){
            	printf("!!Hata!!\nMaksimum fiyat : ");
            	scanf("%d",&maksimum);
			}
            printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
                {
                    if(strcmp(kon[i].ilbilgisi,"\0") && (kon[i].konutfiyat>=minimum && kon[i].konutfiyat<=maksimum))
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
                }
		}

		if(secim!=1&&secim!=2&&secim!=3&&secim!=0){
			printf("\t\t\t  404--Yanlis tus--404\n");
			printf("\t\t    Seciminiz : ")	;
    		scanf("%d",&secim);
		}
		getch();
		system("CLS");
	}while(secim!=0);


}
void katfiltre(){

	system("CLS");
	int secim;

	int i,j,gecicii,gecicid,dolu=0,minimum,maksimum;
	int dizi[500][2];

	for(i=0;i<500;i++){
		dizi[i][0]=i;
		dizi[i][1]=kon[i].konutkat;
		if(strcmp(kon[i].ilbilgisi,"\0"))
		dolu++;
	}

	do{
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("\t\t |  Kat artan sira ile goruntule         : 1   |\n");
		printf("\t\t |  Kat azalan sira ile goruntule        : 2   |\n");
		printf("\t\t |  Kat araligi belirle                  : 3   |\n");
		printf("\t\t |  Cikmak icin                          : 0   |\n");
		printf("\t\t |  ------------------------------------------ |\n");
		printf("\t\t    Seciminiz : ")	;
 	    scanf("%d",&secim);
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

		if(secim==1){
                for(i=0;i<dolu;i++)
            {
                for(j=i;j<dolu;j++)
                {
                    if(dizi[i][1]>dizi[j][1])
                    {
                    	gecicii=dizi[i][0];         gecicid=dizi[i][1];
                    	dizi[i][0]=dizi[j][0];      dizi[i][1]=dizi[j][1];
                    	dizi[j][0]=gecicii;         dizi[j][1]=gecicid;
                    }
                }
           }

			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)

            {
            if(strcmp(kon[dizi[i][0]].ilbilgisi,"\0")){
            	printf("%d\t",i+1);
				printf("%d\t",kon[dizi[i][0]].konutalani);
				printf("%d\t",kon[dizi[i][0]].konutkat);
				printf("%d\t\t",kon[dizi[i][0]].konutfiyat);
				printf("%s\t\t  ",kon[dizi[i][0]].konutdurum);
				printf("%s    ",kon[dizi[i][0]].arsabilgisi);
				printf("%s/",kon[dizi[i][0]].ilbilgisi);
				printf("%s\t  ",kon[dizi[i][0]].ilcebilgisi);
				printf("%s\n",kon[dizi[i][0]].odasayisi);
			}

            }

		}
		if(secim==2){

                for(i=0;i<dolu;i++)
            {
                for(j=i;j<dolu;j++)
                {
                    if(dizi[i][1]<dizi[j][1])
                    {
                    	gecicii=dizi[i][0];         gecicid=dizi[i][1];
                    	dizi[i][0]=dizi[j][0];      dizi[i][1]=dizi[j][1];
                    	dizi[j][0]=gecicii;         dizi[j][1]=gecicid;
                    }
                }
           }

			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)

            {
            if(strcmp(kon[dizi[i][0]].ilbilgisi,"\0")){
            	printf("%d\t",i+1);
				printf("%d\t",kon[dizi[i][0]].konutalani);
				printf("%d\t",kon[dizi[i][0]].konutkat);
				printf("%d\t\t",kon[dizi[i][0]].konutfiyat);
				printf("%s\t\t  ",kon[dizi[i][0]].konutdurum);
				printf("%s    ",kon[dizi[i][0]].arsabilgisi);
				printf("%s/",kon[dizi[i][0]].ilbilgisi);
				printf("%s\t  ",kon[dizi[i][0]].ilcebilgisi);
				printf("%s\n",kon[dizi[i][0]].odasayisi);
			}

            }
		}
		if(secim==3){

            printf("\nEvin kat araligi ne olsun ?");
            printf("\nMinimum kat sayisi : ");
            scanf("%d",&minimum);
            printf("Maksimum kat sayisi : ");
            scanf("%d",&maksimum);
            while(maksimum<minimum){
            	printf("!!Hata!!\nMaksimum kat : ");
            	scanf("%d",&maksimum);
			}            
            printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
                {
                    if(strcmp(kon[i].ilbilgisi,"\0") && (kon[i].konutkat>=minimum && kon[i].konutkat<=maksimum))
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
                }

		}
		if(secim!=1&&secim!=2&&secim!=3&&secim!=0){
			printf("\t\t\t  404--Yanlis tus--404\n");
			printf("\t\t    Seciminiz : ")	;
    		scanf("%d",&secim);
		}
		getch();
		system("CLS");
	}while(secim!=0);
}
void mkarefiltre(){
	int i,j,gecicii,gecicid,dolu=0,minimum,maksimum;
	int dizi[500][2];

	for(i=0;i<500;i++){
		dizi[i][0]=i;
		dizi[i][1]=kon[i].konutalani;
		if(strcmp(kon[i].ilbilgisi,"\0"))
		dolu++;
	}


	system("CLS");
		;
	int secim;
	do{
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("\t\t |  m� artan sira ile goruntule         : 1   |\n");
		printf("\t\t |  m� azalan sira ile goruntule        : 2   |\n");
		printf("\t\t |  m� araligi belirle                  : 3   |\n");
		printf("\t\t |  Cikmak icin                         : 0   |\n");
		printf("\t\t |  ----------------------------------------- |\n");
		printf("\t\t    Seciminiz : ")	;
 	    scanf("%d",&secim);
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

		if(secim==1){
			for(i=0;i<dolu;i++)
            {
                for(j=i;j<dolu;j++)
                {
                    if(dizi[i][1]>dizi[j][1])
                    {
                    	gecicii=dizi[i][0];         gecicid=dizi[i][1];
                    	dizi[i][0]=dizi[j][0];      dizi[i][1]=dizi[j][1];
                    	dizi[j][0]=gecicii;         dizi[j][1]=gecicid;
                    }
                }
           }

			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)

            {
            if(strcmp(kon[dizi[i][0]].ilbilgisi,"\0")){
            	printf("%d\t",i+1);
				printf("%d\t",kon[dizi[i][0]].konutalani);
				printf("%d\t",kon[dizi[i][0]].konutkat);
				printf("%d\t\t",kon[dizi[i][0]].konutfiyat);
				printf("%s\t\t  ",kon[dizi[i][0]].konutdurum);
				printf("%s    ",kon[dizi[i][0]].arsabilgisi);
				printf("%s/",kon[dizi[i][0]].ilbilgisi);
				printf("%s\t  ",kon[dizi[i][0]].ilcebilgisi);
				printf("%s\n",kon[dizi[i][0]].odasayisi);
			}

            }
		}
		if(secim==2){
                for(i=0;i<dolu;i++)
            {
                for(j=i;j<dolu;j++)
                {
                    if(dizi[i][1]<dizi[j][1])
                    {
                    	gecicii=dizi[i][0];         gecicid=dizi[i][1];
                    	dizi[i][0]=dizi[j][0];      dizi[i][1]=dizi[j][1];
                    	dizi[j][0]=gecicii;         dizi[j][1]=gecicid;
                    }
                }
           }

			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)

            {
            if(strcmp(kon[dizi[i][0]].ilbilgisi,"\0")){
            	printf("%d\t",i+1);
				printf("%d\t",kon[dizi[i][0]].konutalani);
				printf("%d\t",kon[dizi[i][0]].konutkat);
				printf("%d\t\t",kon[dizi[i][0]].konutfiyat);
				printf("%s\t\t  ",kon[dizi[i][0]].konutdurum);
				printf("%s    ",kon[dizi[i][0]].arsabilgisi);
				printf("%s/",kon[dizi[i][0]].ilbilgisi);
				printf("%s\t  ",kon[dizi[i][0]].ilcebilgisi);
				printf("%s\n",kon[dizi[i][0]].odasayisi);
			}

            }
		}
		if(secim==3){

            printf("\nEvin metre kare araligi ne olsun ?");
            printf("\nMinimum alan : ");
            scanf("%d",&minimum);
            printf("Maksimum alan : ");
            scanf("%d",&maksimum);
            while(maksimum<minimum){
            	printf("!!Hata!!\nMaksimum alan : ");
            	scanf("%d",&maksimum);
			}            
			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
                {
                    if(strcmp(kon[i].ilbilgisi,"\0") && (kon[i].konutalani>=minimum && kon[i].konutalani<=maksimum))
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
                }
		}
		if(secim!=1&&secim!=2&&secim!=3&&secim!=0){
			printf("\t\t\t  404--Yanlis tus--404\n");
			printf("\t\t    Seciminiz : ")	;
    		scanf("%d",&secim);
		}
	getch();
	system("CLS");
	}while(secim!=0);
}
void arsdurfiltre(){

	system("CLS");
	int secim;
	do{
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("\t\t |  Satilik konutlari goruntule         : 1   |\n");
		printf("\t\t |  Kira konutlari goruntule            : 2   |\n");
		printf("\t\t |  Cikmak icin                         : 0   |\n");
		printf("\t\t |  ----------------------------------------- |\n");
		printf("\t\t    Seciminiz : ")	;
 	    scanf("%d",&secim);
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

		if(secim==1){
			int i;

            printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
            {
                if(strcmp(kon[i].ilbilgisi,"\0") && !strcmp(kon[i].konutdurum,"SATILIK") )
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
            }

		}
		if(secim==2){
			int i ;
			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
            {
                if(strcmp(kon[i].ilbilgisi,"\0") && !strcmp(kon[i].konutdurum,"KIRA") )
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
            }

		}
		if(secim!=1&&secim!=2&&secim!=0){
			printf("\t\t\t  404--Yanlis tus--404\n");
			printf("\t\t    Seciminiz : ")	;
    		scanf("%d",&secim);
		}
	getch();
	system("CLS");
	}while(secim!=0);
}
void arsbilfiltre(){
	system("CLS");
	int i;
	char arsabil[15];
	printf("!!!Turkce Karakter Kullanmayiniz!!!\n");	
	printf("\nKonut arsa bilgisini giriniz(Apartman/Dukkan/Mustakil) : ");
	getchar();
   	gets(arsabil);
	printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

    for(i=0;i<500;i++)

    {
        if(strcmp(kon[i].ilbilgisi,"\0")&&!strcmp(kon[i].arsabilgisi,strupr(arsabil))){
           	printf("%d\t",i+1);
			printf("%d\t",kon[i].konutalani);
			printf("%d\t",kon[i].konutkat);
			printf("%d\t\t",kon[i].konutfiyat);
			printf("%s\t\t  ",kon[i].konutdurum);
			printf("%s    ",kon[i].arsabilgisi);
			printf("%s/",kon[i].ilbilgisi);
			printf("%s\t  ",kon[i].ilcebilgisi);
			printf("%s\n",kon[i].odasayisi);
 		}
     }	
	getch();
	system("CLS");
	
}
void konumbilfiltre(){

	system("CLS");
	int secim,i;
	char il[15],ilce[20];
	do{
		printf("\t\t       !! Turk�e Karaker Kullanmayiniz!!\n");
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("\t\t |  Il bilgisine gore filtrele          : 1   |\n");
		printf("\t\t |  Ilce bilgisine gore filtrele        : 2   |\n");
		printf("\t\t |  Il ve Ilce bilgisine gore filtrele  : 3   |\n");
		printf("\t\t |  Cikmak icin                         : 0   |\n");
		printf("\t\t |  ----------------------------------------- |\n");
		printf("\t\t    Seciminiz : ")	;
 	    scanf("%d",&secim);
		printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

		if(secim==1){
			printf("�l bilgisini giriniz : ");
			getchar();
			gets(il);
			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
            {
                if(strcmp(kon[i].ilbilgisi,"\0") && !strcmp(kon[i].ilbilgisi,strupr(il)) )
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
            }
		}
		if(secim==2){
			printf("�lce bilgisini giriniz : ");
			getchar();
			gets(ilce);
			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
            {
                if(strcmp(kon[i].ilbilgisi,"\0") && !strcmp(strupr(ilce),kon[i].ilcebilgisi) )
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
            }
		}
		
		if(secim==3){
			printf("�l bilgisini giriniz : ");
			getchar();
			gets(il);
			printf("�lce bilgisini giriniz : ");
			gets(ilce);
			printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");

            for(i=0;i<500;i++)
            {
                if(strcmp(kon[i].ilbilgisi,"\0") && !strcmp(kon[i].ilcebilgisi,strupr(ilce))&& !strcmp(kon[i].ilbilgisi,strupr(il)) )
                    {
                        printf("%d\t",i+1);
						printf("%d\t",kon[i].konutalani);
						printf("%d\t",kon[i].konutkat);
						printf("%d\t\t",kon[i].konutfiyat);
						printf("%s\t\t  ",kon[i].konutdurum);
						printf("%s    ",kon[i].arsabilgisi);
						printf("%s/",kon[i].ilbilgisi);
						printf("%s\t  ",kon[i].ilcebilgisi);
						printf("%s\n",kon[i].odasayisi);
                    }
            }
		}
		if(secim!=1&&secim!=2&&secim!=3&&secim!=0){
			printf("\t\t\t  404--Yanlis tus--404\n");
			printf("\t\t    Seciminiz : ")	;
    		scanf("%d",&secim);
    		
		}
	getch();
	system("CLS");
	}while(secim!=0);
}
void odasayfiltre(){
	setlocale(LC_ALL, "Turkish");
	getch();
	system("CLS");
	char oda[8];
	int i;
	printf("Konut oda sayisini giriniz(Oda Sayisi+Salon Sayisi): ");
	getchar();
	gets(oda);
	printf("No\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");
	for(i=0;i<500;i++){
	    if(strcmp(kon[i].ilbilgisi,"\0")&&!strcmp(oda,kon[i].odasayisi)){
	    	printf("%d\t",i+1);
			printf("%d\t",kon[i].konutalani);
			printf("%d\t",kon[i].konutkat);
			printf("%d\t\t",kon[i].konutfiyat);
			printf("%s\t\t  ",kon[i].konutdurum);
			printf("%s    ",kon[i].arsabilgisi);
			printf("%s/",kon[i].ilbilgisi);
			printf("%s\t  ",kon[i].ilcebilgisi);
			printf("%s\n",kon[i].odasayisi);

		}
 }
	getch();
	system("CLS");
}
void cokfiltreleme(){
	system("CLS");
	int i,j,k,*secim,minimumkat,maksimumkat,minimumfiy,maksimumfiy,minimumm2,maksimumm2,dolu=0,dizi[500],l;
	char arsadurum[11],arsabil[10],il[15],ilce[15],oda[8];
	printf("\t\t   !!!Turkce Karakter Kullanmayiniz!!!\n");
	printf("\t\t<><><><><><><><><><><><><><><><><><><><><><><\n");
	printf("\t\t**  Fiyat filterelemesi icin        : 1    **\n");
	printf("\t\t**  Kat bilgisi filtrelemesi icin   : 2    **\n");
	printf("\t\t**  m� bilgisi filtrelemesi icin    : 3    **\n");
	printf("\t\t**  Arsa durumu filtrelemsi icin    : 4    **\n");
	printf("\t\t**  Arsa bilgisi filtrelemsi icin   : 5    **\n");
	printf("\t\t**  Konum bilgisi filtrelemsi icin  : 6    **\n");
	printf("\t\t**  Oda sayisi filtrelemsi icin     : 7    **\n");
	printf("\t\t**  -------------------------------------  **\n");
	printf("\n\t\tSecimlerinizi girdikten sonra secim olarak 0 giriniz.\n");
	
	secim=(int*)malloc(sizeof(int)*7);
	
	for(k=0;k<7;k++){
		printf("\t\tSeciminiz : ");
		scanf("%d",&secim[k]);
		while(secim[k]>7||secim[k]<0){
			printf("\t\t!!HATA!!\n\t\tSeciminiz : ");
			scanf("%d",&secim[k]);
		}
		for(l=0;l<k;l++){
			while(secim[k]==secim[l]){
				printf("\t\tBu secimi daha �nce yaptiniz\n\t\tSeciminiz : ");
				scanf("%d",&secim[k]);
				l=0;
			}
		}
		if(secim[k]==0)
			break;	
	}
	if(secim[0]!=0){
	secim=(int*)realloc(secim,k*sizeof(int*));
	for(j=0;j<8;j++){
		if(secim[j]==1){
			printf("\n\t\tKonut fiyat araligi ne olsun ?");
            printf("\n\t\tMinimum fiyat : ");
            scanf("%d",&minimumfiy);
            printf("\t\tMaksimum fiyat sayisi : ");
            scanf("%d",&maksimumfiy);
            while(maksimumfiy<minimumfiy){
            	printf("\t\t!!Hata!!\n\t\tMaksimum fiyat : ");
            	scanf("%d",&maksimumfiy);
			}            
		}
		if(secim[j]==2){
			printf("\n\t\tKonut kat araligi ne olsun ?");
            printf("\n\t\tMinimum kat sayisi : ");
            scanf("%d",&minimumkat);
            printf("\t\tMaksimum kat sayisi : ");
            scanf("%d",&maksimumkat);
            while(maksimumkat<minimumkat){
            	printf("\t\t!!Hata!!\n\t\tMaksimum kat : ");
            	scanf("%d",&maksimumkat);
			}            
		}
		if(secim[j]==3){
			printf("\n\t\tKonut m� araligi ne olsun ?");
            printf("\n\t\tMinimum m� : ");
            scanf("%d",&minimumm2);
            printf("\t\tMaksimum m� : ");
            scanf("%d",&maksimumm2);
            while(maksimumm2<minimumm2){
            	printf("\t\t!!Hata!!\n\t\tMaksimum m� : ");
            	scanf("%d",&maksimumm2);
			}            
		}
		if(secim[j]==4){
			printf("\n\t\tKonut arsa durumu giriniz(Satilik/Kira) : ");
      		getchar();
			gets(arsadurum);	
		}
		if(secim[j]==5){
			printf("\n\t\tKonut arsa bilgisini giriniz(Apartman/Dukkan/Mustakil) : ");
      		gets(arsabil);
		}
		if(secim[j]==6){
			printf("\n\t\t�l bilgisini giriniz : ");
      		gets(il);
      		printf("\t\t�l�e bilgisini giriniz : ");
      		gets(ilce);
		}
		if(secim[j]==7){
			printf("\n\t\tKonut oda sayisini giriniz(Oda Sayisi+Salon Sayisi): ");
			gets(oda);
		}
		
	}
	for(i=0;i<500;i++){
		dizi[i]=i;
		if(strcmp(kon[i].ilbilgisi,"\0"))
		dolu++;
	}
	for(i=0;i<dolu;i++){
		for(j=0;j<k;j++){
			if(secim[j]==1&&!(minimumfiy<=kon[i].konutfiyat&&maksimumfiy>=kon[i].konutfiyat)){
				dizi[i]=-1;
			}
			if(secim[j]==2&&!(minimumkat<=kon[i].konutkat&&maksimumkat>=kon[i].konutkat)){
				dizi[i]=-1;
			}
			if(secim[j]==3&&!(minimumm2<=kon[i].konutalani&&maksimumm2>=kon[i].konutalani)){
				dizi[i]=-1;
			}
			if(secim[j]==4&&(strcmp(strupr(arsadurum),kon[i].konutdurum))){
				dizi[i]=-1;
			}
			if(secim[j]==5&&(strcmp(strupr(arsabil),kon[i].arsabilgisi))){
				dizi[i]=-1;
			}
			if(secim[j]==6&&(strcmp(strupr(il),kon[i].ilbilgisi)&&strcmp(strupr(ilce),kon[i].ilcebilgisi))){
				dizi[i]=-1;
			}
			if(secim[j]==7&&strcmp(oda,kon[i].odasayisi)){
				dizi[i]=-1;
			}
		}
	}
	printf("\nNo\tm^2\tKat\tFiyat\t     Konut Durumu\tArsa Bilgisi   Il/Ilce\t\t Oda Sayisi\n");
	for(i=0;i<500;i++)
       {
        	if(strcmp(kon[i].ilbilgisi,"\0") && dizi[i]!=-1)
               {
                printf("%d\t",i+1);
				printf("%d\t",kon[i].konutalani);
				printf("%d\t",kon[i].konutkat);
				printf("%d\t\t",kon[i].konutfiyat);
				printf("%s\t\t  ",kon[i].konutdurum);
				printf("%s    ",kon[i].arsabilgisi);
				printf("%s/",kon[i].ilbilgisi);
				printf("%s\t  ",kon[i].ilcebilgisi);
				printf("%s\n",kon[i].odasayisi);
                }
        }		
	}
	

	free(secim);
	getch();
	system("CLS");
}
