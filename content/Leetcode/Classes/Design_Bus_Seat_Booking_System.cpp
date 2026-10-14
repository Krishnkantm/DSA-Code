class BusBooking {
public:
    vector<vector<int>> seats;

    int totalTime = 0;
    int numberOfSeats = 0;

    // time -> O(n)
    // space -> O(n)

    BusBooking(int n) { seats.resize(n, vector<int>(4, 0)); }

    void toggle(string seat) {
        // booked

        char ch = seat[0];
        int col = ch - 'A';

        int row = stoi(seat.substr(1)) - 1;

        if (seats[row][col] > 0) {
            totalTime -= seats[row][col];
            numberOfSeats--;
            seats[row][col] = 0;
        } else {

            // window A
            if (col == 0) {
                if (seats[row][col + 1] > 0) {
                    totalTime += 3;
                    numberOfSeats++;
                    seats[row][col] = 3;
                } else {
                    totalTime += 1;
                    numberOfSeats++;
                    seats[row][col] = 1;
                }
            } // window D
            else if (col == 3) {
                if (seats[row][col - 1] > 0) {
                    totalTime += 3;
                    numberOfSeats++;
                    seats[row][col] = 3;
                } else {
                    totalTime += 1;
                    numberOfSeats++;
                    seats[row][col] = 1;
                }
            } // middle seat B,C => 1,2
            else {
                totalTime += 1;
                numberOfSeats++;
                seats[row][col] = 1;
            }
        }
    }

    int getTotalTime() { return totalTime; }

    int getMinTime() { return numberOfSeats; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
