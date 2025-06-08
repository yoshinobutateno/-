import re
import copy
import sys

wantmatching = 1
filename = "C:\\cygwin\\home\\sugar-v2-3-3\\5^5f.txt"
size = []
block_number = 0 #ブロック数
tmp_y = 0
tmp_x = 0
tmp_block = []
tmp_block2 = []
block_all = []
matching_block = [[0 for i in range(10)] for j in range(10)]
matching_block_all = []
matching_block_all2 = []





with open(filename, "r") as f:
    str1 = f.read().split("\n")
    for i in str1:

        if "SIZE" in i:
            pattern = "\d+"
            result1 = re.match(pattern, i[len("SIZE "):])
            result2 = re.match(pattern, i[::-1])
            size.append([result1.group(),result2.group()[::-1]])

        if "BLOCK_NUM" in i:
            pattern = "\d+"
            result1 = re.match(pattern, i[len("BLOCK_NUM "):])
            block_number = result1.group()

        if "BLOCK#" in i:
            j = i[len("BLOCK#"):]
            j = j.split()[1]
            pattern = "\d+"
            result1 = re.match(pattern, j)
            result2 = re.match(pattern, j[::-1])
            tmp_y, tmp_x = int(result2.group()[::-1]), int(result1.group())
            continue

        if tmp_y:
            j = i.split()
            tmp_block = []
            for k in j:
                if k == "0":
                    tmp_block.append(int(k))
                else:
                    tmp_block.append(1)
            tmp_block2.append(tmp_block)
            tmp_y = tmp_y - 1
            if tmp_y == 0:
                block_all.append(tmp_block2)
                tmp_block2 = []
#block_width = 3
#block_height = 2
map_width = int(sys.argv[1])
map_height = int(sys.argv[2])

'''      
for x,i in enumerate(block_all):
    for y,j in enumerate(block_all[x+1:]):
        block_width = len(i[0])
        block_height = len(i)
        print(f"i[0]={i[0]}")
        print(f"i={i}")
        print("")
        for k in i:
            print(f"k={k}")
        #print("")
        print(f"block_height:{block_height}, block_width:{block_width}")
        block1 = [[1, i+1] for i in range(map_width-1 - block_width + 1)] #上端（列を変更）
        block2 = [[i+1, 1] for i in range(map_height-1 - block_height + 1)] #左端　(行を変更)
        block3 = [[map_height - block_height-1, i+1] for i in range(map_width - block_width-1 + 1)if map_height - block_height - 1 > 0] #下端（列を変更）
        block4 = [[i+1, map_width - block_width-1] for i in range(map_height - block_height-1 + 1) if map_width - block_width - 1 > 0] #右端（行を変更）
        block_all22 = []
        for i in block1,block2,block3,block4:
            #print(i)
            for j in i:
                if j not in block_all22:
                    block_all22.append(j)
        print(block_all22)
        #print("blockall22")
        #exit(1)
        #
       # print("x-y={}-{}".format(x,y+x+1))
    print(len(block_all[x+1:]))
    #
print(f"block_all22[0][1]={block_all22[0]}")
#exit(1)
print(len(block_all22))
'''

block_all33 = []

for x,i in enumerate(block_all):
    block_width = len(i[0])
    block_height = len(i)
    #print(f"i[0]={i[0]}")
    #print(f"i={i}")
    #print("")
    #for k in i:
        #print(f"k={k}")
    #print("")
    #print(f"block_height:{block_height}, block_width:{block_width}")
    block1 = [[1, i+1] for i in range(map_width-1 - block_width + 1)] #上端（列を変更
    block2 = [[i+1, 1] for i in range(map_height-1 - block_height + 1)] #左端　(行を変更)
    block3 = [[map_height - block_height-1, i+1] for i in range(map_width - block_width-1 + 1)if map_height - block_height - 1 > 0] #下端（列を変更）
    block4 = [[i+1, map_width - block_width-1] for i in range(map_height - block_height-1 + 1) if map_width - block_width - 1 > 0] #右端（行を変更）
    block_all22 = []
    for i in block1,block2,block3,block4:
        #print(i)
        for j in i:
            if j not in block_all22:
                block_all22.append(j)
    block_all33.append(block_all22)

#for i in block_all33[0]:
    #print(i)
    
#print(block_all33[0])
#exit(1)


for num,i in enumerate(block_all):#ブロックの種類を指定します
   
    
    extract = []
    for j in range(len(i)):#取り出したブロックの相対座標の抽出
        for k in range(len(i[j])):
            if i[j][k]:
                extract.append([j,k])
    print(f"extract= {extract}")
    print("")
    
    for block_all_tmp in block_all33[num]:
        y, x = block_all_tmp[0], block_all_tmp[1]
        if y + len(i) > map_height or x + len(i[0]) > map_width:#境界条件の判定
            continue
        matching_block = [[0 for i in range(map_height)] for j in range(map_width)] #盤面の生成 
        for y2,x2 in extract:#ブロックを盤面に設置
            matching_block[y+y2][x+x2] |= 1 
        
        for num2, i2 in enumerate(block_all[num+1:]):#最初のブロック以外のブロックを選択
            
            print(f"{num+1} - {num2+1+num+1}")
            
            extract2 = []
            for j in range(len(i2)):
                for k in range(len(i2[j])):
                    if i2[j][k]:
                        extract2.append([j,k])
            
            
            for j in range(len(matching_block) - len(i2)+1):
                for k in range(len(matching_block[0]) - len(i2[0])+1):
                    matching_block2 = copy.deepcopy(matching_block)
                    count = 0
                    for l in extract2:#足し合わせの処理
                        if not matching_block2[j + l[0]][k + l[1]]: #l[0]hay,l[1]hax
                            count += 1
                            matching_block2[j + l[0]][k + l[1]] |= 1 
                     
                    if count != len(extract):
                        for l in range(len(matching_block2)):
                            for m in range(len(matching_block2[l])):
                                print(matching_block2[l][m],end="")
                            print("")
                        print(f"y={y} x={x} block1={num+1}")
                        print(f"y2={j} x2={k} block2={num2+1+num+1}")
                        print(f"blockall{block_all[num+1]}")
                        print(f"extract2{extract2[0]}")
                        
                        if len(block_all[num+1])== 4:
                            print(f"(=> (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                        elif len(block_all[num+1]) == 1:
                            print(f"(=> (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                        elif len(block_all[num+1]) == 2:
                            if len(block_all[num+1][0]) == 2:
                                if y==0 and x==0:
                                    print(f"(=> (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y==0 and x!=0:
                                    print(f"(=> (!= x_{y}_{x-1} {num+1}) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y!=0 and x==0:
                                    print(f"(=> (!= x_{y-1}_{x} {num+1}) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y!=0 and x!=0:
                                    print(f"(=> (&& (!= x_{y}_{x-1} {num+1}) (!= x_{y-1}_{x} {num+1})) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                    
                        elif len(block_all[num+1]) == 3:
                            if block_all[num+1][0][0] == 1:
                                if y==0 and x==0:
                                    print(f"(=> (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y==0 and x!=0:
                                    print(f"(=> (!= x_{y}_{x-1} {num+1}) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y!=0 and x==0:
                                    print(f"(=> (!= x_{y-1}_{x} {num+1}) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y!=0 and x!=0:
                                    print(f"(=> (&& (!= x_{y}_{x-1} {num+1}) (!= x_{y-1}_{x} {num+1})) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                   
                        
                            elif block_all[num+1][0][0] == 0 and block_all[num+1][1][0] == 1 and block_all[num+1][2][0] == 0:
                                if y==0 and x==map_width -2:
                                    print(f"(=> (= x_{y}_{x+1} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y==0 and x!= map_width -2:
                                    print(f"(=> (!= x_{y}_{x-1} {num+1}) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y!=0 and x==map_width -1:
                                    print(f"(=> (!= x_{y-1}_{x} {num+1}) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")
                                elif y!=0 and x!=map_width -1:
                                    print(f"(=> (&& (!= x_{y}_{x-1} {num+1}) (!= x_{y-1}_{x} {num+1})) (= x_{y}_{x} {num+1}) (!= x_{j}_{k} {num2+1+num+1}))")  
                            
                            #elif block_all[num+1][0][0] == 0 and block_all[num+1][1][0] == 1 and block_all[num+1][2][0] == 0:
                                
                                
                                
                                
                        print("")
                
                        
exit(1)

'''
for block_all22 in block_all33:
    for y,x in block_all22:
        # print(f"y={y},x={x}")
        print("a")
        for num,i in enumerate(block_all):
            matching_block = [[0 for i in range(map_height)] for j in range(map_width)] #盤面の生成
            extract = []
        
            for j in range(len(i)):
                for k in range(len(i[j])):
                    if i[j][k]:
                        extract.append([j,k])
            if y + len(i) > map_height or x + len(i[0]) > map_width:
                continue
            
            for y2,x2 in extract:
                matching_block[y+y2][x+x2] |= 1 
        
            for num2, i2 in enumerate(block_all[num+1:]):
            
                print(f"{num} - {num2+1+num}")
            
                extract = []
                for j in range(len(i2)):
                    for k in range(len(i2[j])):
                        if i2[j][k]:
                            extract.append([j,k])
            
            
                for j in range(len(matching_block) - len(i2)+1):
                    for k in range(len(matching_block[0]) - len(i2[0])+1):
                        matching_block2 = copy.deepcopy(matching_block)
                        count = 0
                        for l in extract:#足し合わせの処理
                            if not matching_block2[j + l[0]][k + l[1]]:#l[0]hay,l[1]hax
                                count += 1
                                matching_block2[j + l[0]][k + l[1]] |= 1 

                        if count != len(extract): #被ったとき
                            for l in range(len(matching_block2)):
                                for m in range(len(matching_block2[l])):
                                    print(matching_block2[l][m],end="")
                                print("")
                            print("")
                        
                        for l in range(len(matching_block2)):
                            for m in range(len(matching_block2[l])):
                                print(matching_block2[l][m],end="")
                            print("")
                        print("")
                    
                            
            

            
            
            
            
exit(1)
'''
        
    

matching_count = wantmatching

for x,i in enumerate(block_all):
    if matching_count == wantmatching:#ブロック内になにもおいてない時,ブロックを一個置く時
        matching_block = [[0 for i in range(map_height)] for j in range(map_width)]
        
        for j in range(len(i)):
            for k in range(len(i[j])):
                #print(i[j][k],end = "")
                matching_block[j][k] |= i[j][k]
        matching_count -= 1
        
        
        #exit(1)

        if matching_count != 0 and x == len(block_all) - 1:
            matching_block_all.append(matching_block)
            #print(matching_block_all)
            #print("kore")
            continue


    else:#ブロックをさらに置く時
        extract = []
        for j in range(len(i)):
            for k in range(len(i[j])):
                if i[j][k]:
                    extract.append([j,k])
        count = 0
        #print(extract)
        print("aaa")
        #exit(1)

        for j in range(len(matching_block) - len(i)):
            for k in range(len(matching_block[0]) - len(i[0])):
                matching_block2 = copy.deepcopy(matching_block)
                count = 0
                for l in extract:#足し合わせの処理
                    if not matching_block2[j + l[0]][k + l[1]]:
                        count += 1
                        matching_block2[j + l[0]][k + l[1]] |= 1 

                '''
                if count == len(extract):#（正解か不正解か）
                    matching_block = copy.deepcopy(matching_block2)
                    #break
                '''
                '''
                else:
                    #continue
                '''
                '''
                for l in range(map_width):
                    for k in range(map_height):
                        print(matching_block[l][k], end=" ")
                    print("")
                print("")
                '''
                    
                for l in range(map_width):
                    for k in range(map_height):
                        print(matching_block2[l][k], end=" ")
                    print("")
                print("")
                
                #exit(1)
                
                
            #if count == len(extract):
                #break
        
        if matching_count != 0 and x == len(block_all) - 1:
            matching_block_all.append(matching_block)
            continue

        if matching_count == 0 :
            matching_block_all.append(matching_block)
            matching_block = [[0 for i in range(map_height)] for j in range(map_width)]
            matching_count = wantmatching
            continue
        matching_count -= 1


'''
f = open("C:\\cygwin\\home\\sugar-v2-3-3\\aab.txt", "w")
f.write("SIZE " + str(size[0][0]) + "X" + str(size[0][1]) + "\n")
f.write("BLOCK_NUM " + str(int(len(matching_block_all))) + "\n")
f.write("\n")

for x,i in enumerate(matching_block_all):
    max_right = 0
    max_under = 0
    for j in range(len(i)):
        for k in range(len(i[j])):
            if i[j][k]:
                if max_right < k:
                    max_right = k
                if max_under < j:
                    max_under = j
    #print(max_right)
    #print(max_under)
    #print(x+1)
    f.write("BLOCK#" + str(x+1) + " " + str(max_right+1) + "X" + str(max_under+1) + "\n")
    for j in range(max_under+1):
        for k in range(max_right+1):
            f.write(str(i[j][k]) + " ")
        f.write("\n")
    f.write("\n")
'''
f.close()

