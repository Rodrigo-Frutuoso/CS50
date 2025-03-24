def card_validity(card_num):
    by2 = 0
    notby2 = 0
    num_str = str(card_num)[::-1]

    for i in range(1, len(num_str), 2):
        if int(num_str[i]) * 2 >= 10:
            by2 += int((str(int(num_str[i]) * 2))[0]) + int((str(int(num_str[i]) * 2))[1])
        else:
            by2 += int(num_str[i]) * 2

    for j in range(0, len(num_str), 2):
        notby2 += int(num_str[j])

    totalsum = by2 + notby2

    return totalsum % 10 == 0



def main():
    card_num = input("Number: ")


    if len(card_num) == 13:
        if int(card_num[0:2]) in range(40, 50):
            if card_validity(card_num):
                print("VISA")
                return
            else:
                pass
        else:
            pass

    elif len(card_num) == 15:
        if int(card_num[0:2]) == 34 or int(card_num[0:2]) == 37:
            if card_validity(card_num):
                print("AMEX")
                return
            else:
                pass
        else:
            pass
    elif len(card_num) == 16:
        if int(card_num[0:2]) in range (51, 56):
            if card_validity(card_num):
                print("MASTERCARD")
                return
            else:
                pass
        elif int(card_num[0:2]) in range(40, 50):
            if card_validity(card_num):
                print("VISA")
                return
            else:
                pass
        else:
            pass

    print("INVALID")

if __name__ == '__main__':
    main()
