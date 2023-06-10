with open('input.txt', 'r') as rObj, open('output.txt', 'w') as wObj:
    for line in rObj:
        splits = line.replace('\n', '').split()

        for word in splits:
            wObj.write(f'{word}\n')
