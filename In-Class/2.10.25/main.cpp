// 729. My Calendar I
class MyCalendar {
public:
    using ii = pair<int, int>;
    vector<ii> bookings;

    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        for (ii booking : bookings) {
            int bstart = booking.first;
            int bend = booking.second;
            if ((bstart < endTime && bend > startTime)) {
                return false;
            }
        }
        bookings.push_back({startTime, endTime});
        return true;
    } 
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */