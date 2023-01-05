#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <string.h>
#include <istream>
#include <cstdio>
#include <stdio.h>
#include <fstream>

using namespace std;

class sinhvien
{
public:
    char Ten_[50];
    char GioiTinh_[5];
    unsigned short Tuoi_;
    float DiemToan_;
    float DiemLy_;
    float DiemHoa_;
    float DiemTrungBinh_;
    string HocLuc_;
    int Id_ = 21110000;
    char Name_[20];

public:
    sinhvien();
    ~sinhvien();

public:
    friend ostream &operator<<(ostream &os, sinhvien &sv)
    {
        os << "Ten: " << sv.Ten_ << endl;
        os << "Gioi tinh: " << sv.GioiTinh_ << endl;
        os << "Tuoi: " << sv.Tuoi_ << endl;
        os << "Diem Toan: " << sv.DiemToan_ << endl;
        os << "Diem Ly: " << sv.DiemLy_ << endl;
        os << "Diem Hoa: " << sv.DiemHoa_ << endl;
        os << "Diem Trung Binh: " << sv.DiemTrungBinh_ << endl;
        os << "Hoc Luc: " << sv.HocLuc_ << endl;
        os << "Mssv: " << sv.Id_ << endl;
        return os;
    }
};

typedef class Node *node;

class Node
{
public:
    sinhvien data;
    Node *next;

public:
    Node();
    ~Node();

public:
    node makeNode(sinhvien sv, int id);
    void insertFrist(node &a, sinhvien sv, int sl, int id);
    void insertLast(node &a, sinhvien sv, int sl, int id);
    void insertMiddle(node &a, sinhvien sv, int pos, int sl, int id);
    void deleteFrist(node &a);
    void deleteLast(node &a);
    void deleteMiddle(node &a, int pos);
    int size(node a);
    void coutData(node a);
    int locationDelete(node &a, int idCheck);
    void sortGPA(node &a);
    void sortName(node &a);
    void turnoffName(sinhvien &sv, char name_[]);

public:
    sinhvien nhapthongtinsinhvien(sinhvien &sv, int id);
    void luutrusinhvien(node &a, sinhvien sv, int sl, int id);
    void capnhapthongtinsinhvien(node &a);
    void xoasinhvien(node &a);
    void sapxepsinhvientheoGPA(node &a);
    void sapxepssinhvientheoten(node &a);
    void timkiemsinhvientheoten(node &a);
    void ghidanhsachsinhvienvaofile(node &a);

public:
    void printfLine(int a);
    float GPA(const float &a, const float &b, const float &c);
    string HocLuc(const float &a);
    int Mssv(sinhvien sv, int id);
    int size(char string[]);
    void swap(sinhvien &a, sinhvien &b);
};

#endif
