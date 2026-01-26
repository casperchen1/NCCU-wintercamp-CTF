import hashlib

def check_password(pw):
    h = hashlib.sha256(pw.encode()).hexdigest()
    return h == "0000000000000000000000000000000000000000000000000000000000000000"

def reveal():
    data = [108, 69, 82, 65, 82, 69, 68, 82, 72, 82, 89, 80, 94, 89, 82, 82, 69, 94, 89, 80, 106]
    key = 23
    return "".join(chr(x ^ key) for x in data)

def main():
    print("要取得機密資訊，請輸入正確的密碼")
    pw = input("輸入密碼: ")

    if check_password(pw):
        print("密碼正確")
        print(reveal())
    else:
        print("密碼錯誤")

if __name__ == "__main__":
    main()
