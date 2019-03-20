class Implementation {
  public:
    int calculateAmountToPay(int hours);
};

int Implementation::calculateAmountToPay(int hours) {
    if (hours > 0 && hours < 6)
        return hours * 10;
    else if (hours > 5 && hours < 11)
        return hours * 9;
    else if (hours > 10)
        return hours * 7;
    else
        throw "Error";
}