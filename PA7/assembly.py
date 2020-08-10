# REG 0 - 7 are the available Registers
# Use the Sub Routines to execute Operations
# Usage python3 Target.py optimised code or intermediate code
import re
import sys

if len(sys.argv) != 2:
    print("Correct usage: python3 target.py example.txt\n")
    exit()

def printcode(list_of_lines, message=""):
    print(message.upper())
    for line in list_of_lines:
        print(line.strip())

arithemetic_operations = {'+':'ADD','*':'MUL','-':'SUB','/':'DIV'}
conditional_operations = {'==':'BNE','!=':'BE','<':'BGE','>':'BLE','<=':'BGT','>=':'BLT'}
register_values = {}
register_available = ['REG0','REG1','REG2','REG3','REG4','REG5','REG6','REG7']
register_occupied  = []

def get_register():
    if(not len(register_available) == 0):
        register = register_available.pop(0)
        register_occupied.append(register)
    else:
        register = register_occupied[0]
        register = register_occupied.pop(0)
        register_values.pop(register)
        register_occupied.append(register)
    return register

def check_register(operand):
    for key in register_values.keys():
        if(operand == register_values[key]):
            register = key
            register_occupied.remove(register)
            register_occupied.append(register)
            return register
    register = get_register()
    print("\tMOV {} {}".format(register,operand))
    register_values[register]=operand
    return register

def arithemetic_operation(line,operation):
    register1 = check_register(line[2])
    if(line[4].isnumeric()):
        register2 = line[4]
    else:
        register2 = check_register(line[4])
    register3 = get_register()
    print("\t{} {} {} {}".format(operation,register3,register1,register2))
    
    regex_match= re.findall("^t[0-9]*$",line[0])
    if(len(regex_match)):
        pass
    else:
        print("\tSTR {} {}".format(register3,line[0]))
    
    if(line[0] == line[2]):
        register_occupied.remove(register1)
        register_available.append(register1)
        register_values.pop(register1)
    
    elif(line[0] == line[4] and not line[4].isnumeric()):
        register_occupied.remove(register2)
        register_available.append(register2)
        register_values.pop(register2)
    register_values[register3] = line[0]

def conditional_operation(line):
    register1 = check_register(line[2])
    if(line[4].isnumeric()):
        register2 = line[4]
    else:
        register2 = check_register(line[4])
    print("\tCMP {} {}".format(register1,register2))

condition_used = " "

def eval_statements(line):
    global condition_used
    line = line.split()

    for operator in arithemetic_operations:
        if operator in line and len(line) == 5 :
            arithemetic_operation(line,arithemetic_operations[operator])
            return
    
    for operator in conditional_operations:
        if operator in line and len(line) == 5 :
            condition_used = conditional_operations[operator]
            conditional_operation(line)
            return
    if(len(line) == 1):
        regex_match = re.findall("^[A-Za-z0-9]*:$",line[0])
        if(len(regex_match)):
            print(line[0])
            return
    
    if 'ifFalse' in line and len(line) == 4:
        print("\t{} {}".format(condition_used,line[3]))
        return  

    if 'goto' in line and len(line) == 2:
        print("\tB {}".format(line[1]))
        return
    
    if '=' in line and len(line) == 3:
        register1 = check_register(line[2])
        print("\tSTR {} {}".format(register1,line[0]))
        regex_match= re.findall("^t[0-9]*$",line[2])
        if(line[2].isnumeric() or len(regex_match)):
            pass
        else:
            register2 = get_register()
        
        for register in register_values.keys():
            if(register_values[register] == line[0]):
                register_values.pop(register)
                register_occupied.remove(register)
                register_available.append(register)
                break
        
        if(not line[2].isnumeric() and not len(regex_match)):
            register_values[register2] = line[0]
        if(register_values[register1].isnumeric() or len(regex_match)):
            register_occupied.remove(register1)
            register_occupied.append(register1)
            register_values[register1] = line[0]
        return 
    
if __name__ == "__main__":
    if len(sys.argv) == 2:
        optimized_code = str(sys.argv[1])

    list_of_lines = []
    opti_code = open(optimized_code, "r")
    for line in opti_code:
        list_of_lines.append(line)
    opti_code.close()

    for line in list_of_lines:
        eval_statements(line)