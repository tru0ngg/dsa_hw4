#include <iostream>
#include <string>
using namespace std;

template <class E>
class ArrayList {
        private:
        E* array1;
        int slots;
        int marker;
        int count;

        void make_space() {
                if (count < slots) {
                        return;
                }
                E* array2 = new E[slots * 2];
                for (int i = 0; i < slots; i++) {
                        array2[i] = array1[i];
                }
                delete [] array1;
                array1 = array2;
                slots = slots * 2;
        }

        public:
        ArrayList() {
                slots = 5;
                array1 = new E[slots];
                marker = 0;
                count = 0;
        }

        ~ArrayList() {
                delete [] array1;
        }

        void marker_at(int i) {
                if (i < 0 or i > count){
                        cout << "Invalid operation, marker reset" << endl;
                        marker = 0;
                        return;
                }
                marker = i;
        }

        void add(E x) {
                if (marker < 0 or marker > count) {
                        cout << "Invalid operation, marker reset" << endl;
                        marker = 0;
                }

                make_space();

                for (int i = count; i > marker; i--) {
                        array1[i] = array1[i-1];
                }

                array1[marker] = x;
                count++;
        }

        E remove() {
                if (marker < 0 or marker >= count) {
                        cout << "Invalid operation, marker reset" << endl;
                        marker = 0;
                        return E();
                }

                E ret = array1[marker];

                for (int i = marker; i < count-1; i++) {
                        array1[i] = array1[i+1];
                }
                count--;
                return ret;
        }

        E get() {
                if (marker < 0 or marker >= count) {
                        cout << "Invalid operation, marker reset" << endl;
                        marker = 0;
                        return E();
                }
                return array1[marker];
        }

        void output() {
                cout << "[ ";
                for (int i = 0; i < count; i++) {
                        cout << array1[i] << " ";
                }
                cout << "]" << endl;
                cout << "Count: " << count << ", Slots: " << slots << ", Marker: " << marker << endl;
        }
};



int main() {
        ArrayList<int> mylist;
        string cmd;
        cout << "Enter ArrayList commands" << endl;
        while (true) {
                cin >> cmd;
                if (cmd == "quit" or cin.fail()) {
                        break;
                }
                else if (cmd == "marker_at") {
                        int i;
                        cin >> i;
                        mylist.marker_at(i);
                }
                else if (cmd == "add") {
                        int x;
                        cin >> x;
                        mylist.add(x);
                }
                else if (cmd == "remove") {
                        int x = mylist.remove();
                        cout << "Remove returned " << x << endl;
                }
                else if (cmd == "get") {
                        int x = mylist.get();
                        cout << "Get returned " << x << endl;
                }
                else if (cmd == "output") {
                        mylist.output();
                }
        }
        cout << "Goodbye!" << endl;
        return 0;
}
