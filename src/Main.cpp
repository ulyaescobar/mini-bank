#include <iostream>
#include <conio.h>
using namespace std;

// siapin ruang antrian
struct antrianAtmLL{
  // data / member
  string nama;
  int umur;

  // pointer next
  antrianAtmLL *next;
};

int maksimalAntrianLinkedList;
antrianAtmLL *head, *tail, *cur, *del, *newNode;

// count Linked List
int countLinkedList(){
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

// isFull Linked List
bool isFullLinkedList(){
  if( countLinkedList() == maksimalAntrianLinkedList ){
    return true;
  }else{
    return false;
  }
}

// isEmpty Linked List
bool isEmptyLinkedList(){
  if( countLinkedList() == 0 ){
    return true;
  }else{
    return false;
  }
}

// enqueue / penambahan
void enqueueLinkedList( string nama, int umur ){

  if( isFullLinkedList() ){
    cout << "Antrian Penuh!!!" << endl;
    cout << "Mohon maaf data tidak bisa di input" << endl;
  }else{
    
    if( isEmptyLinkedList() ){
      head = new antrianAtmLL();
      head->nama = nama;
      head->umur = umur;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianAtmLL();
      newNode->nama = nama;
      newNode->umur = umur;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

// dequeue Linked List
void dequeueLinkedList(){
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    del = head;
    cout << "Silahkan " << head->nama << " giliran kamu" << endl;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

// destroy / clear
void clearLinkedList(){
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}

// display Linked List
void displayLinkedList(){
  cout << "Data Antrian : " << endl;
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    cout << "Banyak data antrian : " << countLinkedList() << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedList ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->nama << " - " << cur->umur << " tahun." << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }

      nomor++;
    }

  }

  cout << "\n" << endl;

}

struct transaksi {
  string namaNasabah;
  int nominal;

  transaksi *next1;
  transaksi *prev1;
};
transaksi *head1, *tail1, *newnode1, *cur1, *afternode, *del1; 

void creataDLL(string namaNasabah, int nominal){
  
  if (head1 == NULL){
    head1 = new transaksi();
    head1->namaNasabah = namaNasabah;
    head1->nominal = nominal;

    head1->next1 = head1;
    head1->prev1 = head1;
    tail1 = head1;
  }else{
    newnode1 = new transaksi();
    newnode1->namaNasabah = namaNasabah;
    newnode1->nominal = nominal;

    newnode1->next1 = head1;
    newnode1->prev1 = tail1;
    head1->prev1 = newnode1;
    tail1->next1 = newnode1;
    head1 = newnode1;
  }
}

void delFirst(){
  if (head1 == NULL){
    cout << "Data tabungan masi kosong, silahkan input!" << endl;
  }else{
    del1 = head1;
    cout << "Hai " << head1->namaNasabah;
    cout << " Uangmu sebesar " << head1->nominal;
    cout << " Telah diambil, Terimakasih";
    head1 = head1->next1;
    head1->prev1 = tail1;
    tail1->next1 = head1;
    delete del;
  }
}

void print(){
    cur1 = head1;
    while(cur1->next1 != head1){
      //print
      cout << "Hai: " << cur1->namaNasabah << endl;
      cout << "Tabungan kamu: " << cur1->nominal << endl;

      cur1 = cur1->next1;
    }
    //print last node
    cout << "Hai: " << cur1->namaNasabah << endl;
    cout << "Tabungan kamu: " << cur1->nominal << endl << endl;
}

int main(){

  bool keluar = false;
  int pilih;
  char ya_tidak;
  string nama;
  int usia;

  pijakan:
  system("cls");
  cout << "Masukkan maks antrean pada hari ini : ";
  cin >> maksimalAntrianLinkedList;
  system("cls");

  awal:
  do{

    //menu pilihan
    cout << "\t\t\tsiapakah anda?" << endl;
    cout << "\t\t\t==============" << endl;
    cout << "1. petugas" << endl;
    cout << "2. nasabah" << endl;
    cout << "3. keluar" << endl;

    cout << "Silahkan masukkan pilihan: ";
    cin >> pilih;
    switch(pilih){
      case 1:
      system("cls");
      goto petugas;
      break;

      case 2:
      system("cls");
      goto nasabah;
      break;

      case 3:
      cout << "Apakah yakin ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        cout << "Terima kasih" << endl;
        keluar = true;
      }else{
        system("cls");
      }
      break;

      default:
      cout << "Maaf pilihan tidak tersedia!!!" << endl;
      getch();
      system("cls");
      break;
    }
  }while(keluar == false);
  goto ahir;

  petugas:
  do{
    
    //menu pilihan
    cout << "\t\t\tMENU PETUGAS" << endl;
    cout << "\t\t\t============" << endl;
    cout << "1. panggil antrian" << endl;
    cout << "2. hapus semua data antrian" << endl;
    cout << "3. tampil data antrian" << endl;
    cout << "4. reset pengaturan" << endl;
    cout << "5. Keluar" << endl << endl;

    //menu pilihan antrian
    cout << "Silahkan masukkan pilihan: ";
    cin >> pilih;
    switch(pilih){
      case 1:
      system("cls");
      dequeueLinkedList();
      getch();
      system("cls");
      cout << "Jika antrian kosong tekan 'y'" << endl;
      cout << "jika tidak tekan 'n'" << endl;
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto petugas;
      }else{
        system("cls");
        goto transaksi;
      }
      break;
      
      case 2:
      clearLinkedList();
      cout << "Apakah anda ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto petugas;
      }
      break;

      case 3:
      displayLinkedList();
      cout << "Apakah anda ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto petugas;
      }
      break;

      case 4:
      cout << "Apakah anda ingin reset pengaturan?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto pijakan;
      }else{
        system("cls");
        goto petugas;
      }
      break;
      
      case 5:
      cout << "Apakah yakin ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto petugas;
      }
      break;

      default:
      cout << "Maaf pilihan tidak tersedia!!!" << endl;
      cout << "Apakah anda ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto petugas;
      }
      break;

    }
  }while(keluar == false);

  nasabah:
  do{
    
    //menu pilihan
    cout << "\t\t\tMENU NASABAH" << endl;
    cout << "\t\t\t=======" << endl;
    cout << "1. masukkan data antrean" << endl;
    cout << "2. data urutan antrian" << endl;
    cout << "3. Keluar" << endl << endl;

    //menu pilihan antrian
    cout << "Silahkan masukkan pilihan: ";
    cin >> pilih;
    switch(pilih){
      case 1:
      cout << "Masukkan nama: ";
      cin.ignore();
      getline(cin, nama);
      cout << "Masukkan usia: ";
      cin >> usia;
      enqueueLinkedList(nama,usia);
      cout << "Apakah anda ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto nasabah;
      }
      break;

      case 2:
      displayLinkedList();
      cout << "Apakah anda ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto nasabah;
      }
      break;

    
      case 3:
      cout << "Apakah yakin ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto nasabah;
      }
      break;

      default:
      cout << "Maaf pilihan tidak tersedia!!!" << endl;
      cout << "Apakah anda ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        goto awal;
      }else{
        system("cls");
        goto nasabah;
      }
      break;

    }
    
  }while(keluar == false);
  
  transaksi:
  system("cls");
  do{

    string namaCst;
    int uang;

    //menu transaksi
    cout << "\t\t\tMENU TRANSAKSI NASABAH" << endl;
    cout << "\t\t\t======================" << endl;
    cout << "1. Menabung" << endl;
    cout << "2. penarikan" << endl;
    cout << "3. data rekening tabungan" << endl;
    cout << "4. keluar" << endl;

    cout << "Silahkan masukkan pilihan: ";
    cin >> pilih;
    switch(pilih){
      case 1:
      system("cls");
      cout << "Silahkan masukkan nama: ";
      cin.ignore();
      getline(cin, namaCst);
      cout << "Silahkan masukkan nominal: ";
      cin >> uang;
      creataDLL(namaCst, uang);
      cout << "Data telah masuk" << endl;
      getch();
      goto transaksi;

      case 2:
      system("cls");
      delFirst();
      cout << endl;
      getch();
      system("cls");
      break;

      case 3:
      system("cls");
      print();
      cout << endl;
      getch();
      goto transaksi;
      
      break;

      case 4:
      cout << "Apakah yakin ingin keluar?[y/n] : ";
      cin >> ya_tidak;
      if (ya_tidak == 'y'){
        system("cls");
        keluar = true;
      }else{
        system("cls");
        goto transaksi;
      }
    }
  }while(keluar == false);
  goto petugas;


  ahir:
  return 0;
}
