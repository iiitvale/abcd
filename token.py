def datatype(s):
    list = ['int','string','char','char*','bool','float','double','long','long long']
    if s in list:
        return True
    return False

def keyword(s):
    list = ['main','if','else','for','void','return','cin','cout']
    if s in list:
        return True
    return False

def operator(s):
    list = ['+','-','*','/','=','==','&&','||','!=',':','?','|']
    if s in list:
        return True
    return False

def parenthesis(s):
    list = ['(',')','()','{','}','{}']
    if s in list:
        return True
    return False

def seperator(s):
    list = [',',';']
    if s in list:
        return True
    return False

def id(s):
    if s.isalpha() == True or s == "_":
        return True
    else:
        return False

def take_input():
    global input_list
    while True:
        inp = input()
        if inp!="":
            inp+=" "

            input_list.append(inp)
        else:
            break

count,count_token,chk,eq = 0,0,0,0
check_for_identifier_after_datatype = 1
idf = list()
t=""

print("Enter the code: \n")
input_list = []
take_input()

for inp in input_list:
    if inp!="":
        if inp[0] == "/" and len(inp) > 1:
            if inp[1] == '/':
                print(inp," Comment")
            elif inp[1] == "*":
                t+=inp[2:]
                chk = 1
                if inp[-1] == '/' and inp[-2] == '*':
                    print(inp, "Comment")
                    t = ""
                    chk = 0
        elif chk:
            t+=inp
            if inp[-1] == '/' and inp[-2] == '*':
                print(inp, " Comment ")
                t=""
                chk=0
        else:
            for j in inp:

                if j != " ":
                    t=t+j
                else:
                    if (len(t)):
                        if datatype(t):
                            print(f"{t} Datatype")
                            check_for_identifier_after_datatype = 1
                            count_token+=1
                        elif keyword(t):
                            print(f"{t} Keyword")
                            count_token+=1
                        elif operator(t):
                            print(f"{t} Operator")
                            count_token +=1
                            if t == "=":
                                eq = 1
                        elif seperator(t):
                            print(f"{t} Seperator:")
                            count_token+=1
                        elif parenthesis(t):
                            print(f"{t} Parenthesis: ")
                            count_token += 1
                        elif id(t):
                            if(check_for_identifier_after_datatype):
                                print(f"{t} Identifier")
                                check_for_identifier_after_datatype = 0
                                count_token+=1
                            else:
                                c = 0
                                for x in idf:
                                    if x == t:
                                        c = 1
                                        count_token+=1
                                if not c:
                                    if t[0] >= 'a' and t[0] <= 'z':
                                        print(f"{t} Identifier: ")
                                        count_token+=1
                                    elif t[0] >= 'A' and t[0] <= 'Z':
                                        print(f"{t} Identifier: ")
                                        count_token += 1
                                    else:
                                        print(f"{t} Not a valid identifier")
                        elif eq:
                            print(f"{t} Value")
                            count_token+=1
                            eq = 0
                        else:
                            if (t[0] >= '0'and t[0] <= '9' and t[len(t) - 1] >= '0' and t[len(t) - 1] <= '9'):
                                flag1 = True
                                for i in range(0,t.length()):
                                    if t[i]>='a' and t[i] <= 'z':
                                        flag1 = False
                                        break
                                    if t[i]>='A' and t[i] <= 'Z':
                                        flag1 = False
                                        break
                                #above for intergers and invalid_stuff like 1a
                                if flag1:
                                    print(f"{t} value")
                                    count_token+=1
                                else:
                                    print("Invalid")
                            elif t[0]>='a' and t[0] <= 'z':
                                print(f"{t} Identifier")
                                count_token+=1
                            elif t[0]>='A' and t[0] <= 'Z':
                                print(f"{t} Identifier")
                                count_token+=1
                            else:
                                print(f"{t} Invalid")

                        t = "";

print("Total string are ", count_token)

if __name__ == "__main__":
    pass
