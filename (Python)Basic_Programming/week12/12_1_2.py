
with open('input.txt', 'r') as fileOBJ:
    for line in fileOBJ:
        splits = line.replace('\n', '').split()
        open('input.txt', 'w')
        for word in splits:
            fileOBJ.writelines(splits)
    # l = []
    # f = fileOBJ.readline()
    # l = f.split(' ')
    # fout = open('input.txt', 'w')
    # fout.writelines(l)