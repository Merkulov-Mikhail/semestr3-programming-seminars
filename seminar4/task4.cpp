#include <iostream>
#include <string>
#include <vector>


class Time {
private:
    int mHours, mMinutes, mSeconds;

public:
    Time(int hours, int minutes, int seconds): mHours(hours), mMinutes(minutes), mSeconds(seconds) {}

    Time(const std::string& s) {
        mHours = s[0] - '0';
        mHours = mHours * 10 + s[1] - '0';

        mMinutes = s[3] - '0';
        mMinutes = mMinutes * 10 + s[4] - '0';

        mSeconds = s[6] - '0';
        mSeconds = mSeconds * 10 + s[7] - '0';
    }

    Time operator+(Time b) const {
        Time tmp = b;
        tmp.mSeconds += mSeconds;
        tmp.mMinutes += mMinutes;
        tmp.mHours   += mHours;

        tmp.mMinutes += tmp.mSeconds / 60;
        tmp.mHours   += tmp.mMinutes / 60;
        tmp.mSeconds %= 60;
        tmp.mMinutes %= 60;
        tmp.mHours %= 24;

        return tmp;
    }

    int hours() const {
        return mHours;
    }

    int minutes() const {
        return mMinutes;
    }

    int seconds() const {
        return mSeconds;
    }

    friend std::ostream& operator<<(std::ostream& out, Time T);

};

std::vector<Time> getTimesFromString(const std::string& s) {
    std::vector<Time> st;
    std::string lmao;

    for (int pos = 0; pos < s.size(); pos++) {
        if (s[pos] == ' ') {
            st.push_back(Time(lmao));
            lmao.clear();
        }
        else {
            lmao += s[pos];
        }
    }

    if (lmao.size() > 0) {
        st.push_back(Time(lmao));
    }

    return st;
}

Time sumTimes(const std::vector<Time>& v) {
    Time t(0, 0, 0);

    for (Time a: v) {
        t = t + a;
    }
    return t;
}

std::ostream& operator<<(std::ostream& out, Time T) {
    if (T.mHours < 10)
        out << "0";
    out << T.mHours << ":";

    if (T.mMinutes < 10)
        out << "0";
    out << T.mMinutes << ":";

    if (T.mSeconds < 10)
        out << "0";
    out << T.mSeconds;
    return out;
}

int main() {
    std::vector<Time> v = getTimesFromString(std::string{"11:20:05 05:45:30 22:10:45"});
    v.push_back(Time("01:10:30"));
    Time s = sumTimes(v);
    std::cout << s << std::endl;
}
