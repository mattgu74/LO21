#ifndef CINEMAEXCEPTION_H
#define CINEMAEXCEPTION_H


class CinemaException {
public:
    CinemaException(const std::string& m):info(m){}
    const std::string& GetInfo() const { return info; }
private:
    std::string info;
};

#endif

