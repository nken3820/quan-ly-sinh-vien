#include "data.h"

static int sl_ = 0;
static bool check_ = true;
static int key_continue;
static int id_ = 0;

int main()
{
    int keynumber = 0;
    int size = 0;

    sinhvien sv_;
    node node_ = NULL;

    while (check_)
    {
        cout << "****************** # # # # MENU # # # # ******************" << endl;
        cout << "**                                                      **" << endl;
        cout << "**            CHUONG TRINH QUAN LY SINH VIEN            **" << endl;
        cout << "**                                                      **" << endl;
        cout << "**  1.Them sinh vien                                    **" << endl;
        cout << "**  2.Cap nhap thong tin sinh vien boi ID               **" << endl;
        cout << "**  3.Xoa sinh vien boi ID                              **" << endl;
        cout << "**  4.Tim kiem sinh vien theo ten                       **" << endl;
        cout << "**  5.Sap xep sinh vien theo diem trung binh (GPA)      **" << endl;
        cout << "**  6.Sap xep sinh vien theo ten                        **" << endl;
        cout << "**  7.Hien thi danh sach sinh vien                      **" << endl;
        cout << "**  8.Ghi danh sach sinh vien vao file student.txt      **" << endl;
        cout << "**  0.Thoat                                             **" << endl;
        cout << "**                                                      **" << endl;
        cout << "**********************************************************" << endl;

        cout << "chon chuc nang: ";
        cin >> keynumber;
        cin.ignore();
        cout << endl;

        switch (keynumber)
        {
        case 1:

            key_continue = keynumber;
            cout << "Them sinh vien: ";

            while (key_continue == 1)
            {
                node_->printfLine(60);
                cout << "Sinh vien thu " << sl_ + 1 << endl;
                node_->luutrusinhvien(node_, sv_, sl_, id_);
                id_++;
                node_->printfLine(60);
                cout << "nhan 1 de tiep tuc, 0 de thoat [1/0]: ";
                cin >> key_continue;
                cin.ignore();
                sl_++;
            }
            break;

        case 2:

            cout << "Cap nhap thong tin sinh vien boi ID  " << endl;
            key_continue = keynumber;

            while (key_continue == 2)
            {
                node_->printfLine(60);
                node_->capnhapthongtinsinhvien(node_);
                node_->printfLine(60);
                cout << "nhan 2 de tiep tuc, 0 de thoat [2/0]: ";
                cin >> key_continue;
                cin.ignore();
            }
            break;

        case 3:

            cout << "Xoa sinh vien boi ID: " << endl;
            key_continue = keynumber;

            while (key_continue == 3)
            {
                node_->printfLine(60);
                node_->xoasinhvien(node_);
                node_->printfLine(60);
                cout << "nhan 3 de tiep tuc, 0 de thoat [3/0]: ";
                cin >> key_continue;
                cin.ignore();
            }
            break;

        case 4:

            cout << "Tim kiem sinh vien theo ten: " << endl;
            key_continue = keynumber;

            while (key_continue == 4)
            {
                node_->printfLine(60);
                node_->timkiemsinhvientheoten(node_);
                node_->printfLine(60);
                cout << "nhan 4 de tiep tuc, 0 de thoat [4/0]: ";
                cin >> key_continue;
                cin.ignore();
            }
            break;

        case 5:

            cout << "Sap xep sinh vien theo diem trung binh (GPA): " << endl;
            node_->sapxepsinhvientheoGPA(node_);
            cout << endl;
            node_->coutData(node_);
            cout << "Danh sach sinh vien sau khi sap xep! " << endl
                 << endl;
            break;

        case 6:

            cout << "Sap xep sinh vien theo ten: " << endl;
            node_->sapxepssinhvientheoten(node_);
            cout << endl;
            node_->coutData(node_);
            cout << "Danh sach sinh vien sau khi sap xep! " << endl
                 << endl;
            break;

        case 7:

            size = node_->size(node_);
            if (size == 0)
            {
                cout << "Danh sach sinh vien: " << endl;
                cout << "                     " << endl;
                cout << "       Trong!        " << endl
                     << endl;
            }
            else
            {
                cout << "Danh sach sinh vien: " << endl
                     << endl;
                node_->coutData(node_);
            }

            break;
        case 8:

            cout << "Ghi danh sach sinh vien vao file student.txt thanh cong! " << endl
                 << endl;
            node_->ghidanhsachsinhvienvaofile(node_);
            break;

        case 0:
            check_ = false;
            break;

        default:
            break;
        }
    }

    return 0;
}
