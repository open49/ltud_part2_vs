pw = input("nhap password: ")
co_viethoa, co_vietthuong, co_so, co_dacbiet= 0,0,0,0
if(len(pw) > 8 ):
    for c in pw:
        if(c.isupper()):
            co_viethoa = 1
        elif(c.islower()):
            co_vietthuong = 1
        elif(c.isdigit()):
            co_so = 1
        else:
            co_dacbiet = 1
    if(co_viethoa + co_vietthuong + co_so + co_dacbiet == 4):
        print("strong password")
    else:
        print("weak password")
else:
    print("weak password")