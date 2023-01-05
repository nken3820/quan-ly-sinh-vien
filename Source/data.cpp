#include "data.h"

///// class sinhvien

sinhvien::sinhvien()
{
    Ten_[50];
    GioiTinh_[5];
    Tuoi_ = 0;
    DiemToan_ = 0;
    DiemLy_ = 0;
    DiemHoa_ = 0;
    DiemTrungBinh_ = 0;
    HocLuc_ = "";
    Id_ = 21110000;
    Name_[20];
}

sinhvien::~sinhvien()
{
}

///// class Node

Node::Node()
{
    data = sinhvien();
    next = NULL;
}

Node::~Node()
{
}

///// sub fuction

void Node::printfLine(int a)
{
    cout << endl;
    for (int i = 0; i < a; i++)
    {
        cout << "-";
    }
    cout << endl;
}

float Node::GPA(const float &a, const float &b, const float &c)
{
    float result = (a + b + c) / 3;
    return result;
}

string Node::HocLuc(const float &a)
{
    string result;
    if (a >= 8)
    {
        result = "GIOI";
    }
    else if (a < 8 && a >= 6.5)
    {
        result = "KHA";
    }
    else if (a < 6.5 && a >= 5)
    {
        result = "Trung Binh";
    }
    else if (a < 5)
    {
        result = "YEU";
    }
    return result;
}

int Node::Mssv(sinhvien sv, int id)
{
    sv.Id_ = sv.Id_ + id;
    return sv.Id_;
}

int Node::size(char string[])
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void Node::turnoffName(sinhvien &sv, char name_[])
{
    int siz = size(name_);
    int index = 0;

    for (int i = siz; i > 0; i--)
    {
        if (name_[i] == ' ')
        {
            index = i;
            break;
        }
    }

    int b = siz - index + 1;
    strncpy(sv.Name_, name_ + index + 1, b);
}

///// main function

int Node::size(node a)
{
    int count = 0;
    while (a != NULL)
    {
        count++;
        a = a->next;
    }
    return count;
}

int Node::locationDelete(node &a, int idCheck)
{
    int pos = 0;
    while (a->data.Id_ != idCheck)
    {
        pos++;
        a = a->next;
    }
    return pos;
}

node Node::makeNode(sinhvien sv, int id)
{
    node newnode = new Node();
    newnode->data = nhapthongtinsinhvien(sv, id);
    newnode->next = NULL;
    return newnode;
}

void Node::insertFrist(node &a, sinhvien sv, int sl, int id)
{
    node tmp = makeNode(sv, id);
    if (a == NULL)
    {
        a = tmp;
        return;
    }
    else
    {
        tmp->next = a;
        a = tmp;
    }
    cout << "Them sinh vien thanh cong!" << endl
         << endl;
    cout << "So luong sinh vien: " << sl + 1;
}

void Node::insertLast(node &a, sinhvien sv, int sl, int id)
{
    node tmp = makeNode(sv, id);
    if (a == NULL)
    {
        a = tmp;
        return;
    }
    else
    {
        node p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
    cout << "Them sinh vien thanh cong!" << endl
         << endl;
    cout << "So luong sinh vien: " << sl + 1;
}

void Node::insertMiddle(node &a, sinhvien sv, int pos, int sl, int id)
{
    int n = size(a);
    if (pos <= 0 || pos > n + 1)
    {
        cout << endl
             << "vi tri them khong hop le " << endl;
        return;
    }
    else
    {
        if (n == 1)
        {
            insertFrist(a, sv, sl, id);
            return;
        }
        else if (n == pos + 1)
        {
            insertLast(a, sv, sl, id);
            return;
        }
        else
        {
            node p = a;
            for (int i = 1; i < pos; i++)
            {
                p = p->next;
            }
            node tmp = makeNode(sv, id);
            tmp->next = p->next;
            p->next = tmp;
            cout << "Them sinh vien thanh cong!" << endl
                 << endl;
            cout << "So luong sinh vien: " << sl + 1;
            return;
        }
    }
}

void Node::deleteFrist(node &a)
{
    if (a == NULL)
    {
        cout << "Xoa sinh vien thanh cong! " << endl;
        return;
    }
    else
    {
        a = a->next;
        cout << "Xoa sinh vien thanh cong! " << endl;
        return;
    }
}

void Node::deleteLast(node &a)
{
    if (a == NULL)
    {
        cout << "Xoa sinh vien thanh cong! " << endl;
        return;
    }
    else
    {
        node truoc = NULL;
        node sau = a;
        while (sau->next != NULL)
        {
            truoc = sau;
            sau = sau->next;
        }
        if (truoc == NULL)
        {
            a = NULL;
            cout << "Xoa sinh vien thanh cong! " << endl;
            return;
        }
        else
        {
            truoc->next = NULL;
            cout << "Xoa sinh vien thanh cong! " << endl;
            return;
        }
    }
}

void Node::deleteMiddle(node &a, int pos)
{
    int n = size(a);
    node truoc = NULL;
    node sau = a;
    for (int i = 1; i < pos; i++)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL)
    {
        a = a->next;
        cout << "Xoa sinh vien thanh cong! " << endl;
        return;
    }
    else
    {
        truoc->next = sau->next;
        cout << "Xoa sinh vien thanh cong! " << endl;
        return;
    }
}

void Node::swap(sinhvien &a, sinhvien &b)
{
    sinhvien temp = a;
    a = b;
    b = temp;
}

void Node::sortGPA(node &a)
{
    for (node truoc = a; truoc->next != NULL; truoc = truoc->next)
    {
        for (node sau = truoc->next; sau != NULL; sau = sau->next)
        {
            if (truoc->data.DiemTrungBinh_ > sau->data.DiemTrungBinh_)
            {
                swap(truoc->data, sau->data);
            }
        }
    }
}

void Node::sortName(node &a)
{
    node truoc = a;
    node sau = truoc->next;

    turnoffName(truoc->data, truoc->data.Ten_);
    turnoffName(sau->data, sau->data.Ten_);

    for (truoc; truoc->next != NULL; truoc = truoc->next)
    {
        for (sau; sau != NULL; sau = sau->next)
        {
            int result_sort = strcmp(truoc->data.Name_, sau->data.Name_);
            if (result_sort > 0)
            {
                swap(truoc->data, sau->data);
            }
        }
    }
}

void Node::coutData(node a)
{
    while (a != NULL)
    {
        cout << a->data << endl;
        a = a->next;
    }
}

///// controler function

sinhvien Node::nhapthongtinsinhvien(sinhvien &sv, int id)
{
    cout << "Ten: ";
    cin.getline(sv.Ten_, sizeof(sv.Ten_) + 1);
    cout << "Gioi tinh: ";
    cin.getline(sv.GioiTinh_, sizeof(sv.GioiTinh_) + 1);
    cout << "Tuoi: ";
    cin >> sv.Tuoi_;
    cout << "Diem Toan: ";
    cin >> sv.DiemToan_;
    cout << "Diem Ly: ";
    cin >> sv.DiemLy_;
    cout << "Diem Hoa: ";
    cin >> sv.DiemHoa_;
    cin.ignore();
    sv.DiemTrungBinh_ = GPA(sv.DiemToan_, sv.DiemLy_, sv.DiemHoa_);
    cout << "GPA: " << sv.DiemTrungBinh_ << endl;
    sv.HocLuc_ = HocLuc(sv.DiemTrungBinh_);
    cout << "Hoc Luc: " << sv.HocLuc_ << endl;
    sv.Id_ = Mssv(sv, id);
    cout << "Mssv: " << sv.Id_ << endl;
    return sv;
}

void Node::luutrusinhvien(node &a, sinhvien sv, int sl, int id)
{
    int keywork;
    printfLine(40);
    cout << endl;
    cout << "nhan 2 neu muon them vao dau          " << endl;
    cout << "nhan 1 neu muon them vao cuoi         " << endl;
    cout << "nhan 0 neu muon them vao vi tri bat ki" << endl;
    cout << "chon cach them: ";
    cin >> keywork;
    cin.ignore();
    printfLine(40);
    if (keywork == 1)
    {
        insertLast(a, sv, sl, id);
        return;
    }
    else if (keywork == 2)
    {
        insertFrist(a, sv, sl, id);
        return;
    }
    else if (keywork == 0)
    {
        int pos;
        cout << "chon vi tri muon them: ";
        cin >> pos;
        cin.ignore();
        insertMiddle(a, sv, pos, sl, id);
        return;
    }
    else
    {
        cout << "Lua chon them khong hop le! ";
    }
}

void Node::capnhapthongtinsinhvien(node &a)
{
    printfLine(20);
    cout << endl;
    int idUpdate = 0;
    cout << "nhap ID: ";
    cin >> idUpdate;
    cin.ignore();
    printfLine(20);
    int id = idUpdate - 21110000;
    int siz = size(a);
    if (siz == 0)
    {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }
    else
    {
        // id--;
        if (idUpdate == a->data.Id_)
        {
            nhapthongtinsinhvien(a->data, id);
            return;
        }
    }
}

void Node::xoasinhvien(node &a)
{
    int siz = size(a);
    if (siz == 0)
    {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }
    else
    {
        int keywork;
        printfLine(40);
        cout << endl;
        cout << "nhan 2 neu muon xoa o dau          " << endl;
        cout << "nhan 1 neu muon xoa o cuoi         " << endl;
        cout << "nhan 0 neu muon xoa o vi tri bat ki" << endl;
        cout << "chon cach xoa: ";
        cin >> keywork;
        cin.ignore();
        printfLine(40);
        if (keywork == 1)
        {
            deleteLast(a);
            return;
        }
        else if (keywork == 2)
        {
            deleteFrist(a);
            return;
        }
        else if (keywork == 0)
        {
            int pos = 0;
            printfLine(20);
            cout << endl;
            int idDetele = 0;
            cout << "nhap ID: ";
            cin >> idDetele;
            cin.ignore();
            printfLine(20);
            if (idDetele == a->data.Id_)
            {
                pos = locationDelete(a, idDetele);
                deleteMiddle(a, pos);
                return;
            }
        }
        else
        {
            cout << "Lua chon xoa khong hop le! ";
            return;
        }
    }
}

void Node::sapxepsinhvientheoGPA(node &a)
{
    sortGPA(a);
}

void Node::sapxepssinhvientheoten(node &a)
{
    sortName(a);
}

void Node::timkiemsinhvientheoten(node &a)
{
    node temp = a;
    char Name[50];
    cout << "Nhap ten sinh vien: ";
    cin.getline(Name, sizeof(Name) + 1);
    cout << endl;
    cout << "Ket qua tim kiem! " << endl;
    printfLine(25);
    while (temp != NULL)
    {
        int keySearch = strcmp(Name, temp->data.Ten_);
        if (keySearch == 0)
        {
            cout << temp->data;
        }
        temp = temp->next;
    }
    printfLine(25);
}

void Node::ghidanhsachsinhvienvaofile(node &a)
{
    int index = 0;
    node temp = a;
    ofstream student;
    student.open("student.txt", ios::out);

    student << "Danh sach sinh vien" << endl
            << endl
            << endl;

    while (temp != NULL)
    {
        student << "Sinh vien thu: " << index + 1 << endl
                << endl;
        student << temp->data << endl
                << endl;
        index++;
        temp = temp->next;
    }

    student.close();
}