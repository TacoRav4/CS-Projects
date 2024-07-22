# Homework 5 part 6
# Jason Zhang
#
#  Create a .csv file 

#Input
file=input('Temperature anomaly filename:')
index=int(input('Enter window size:'))
infile=open(file,'r')

#Ignore the header
infile.readline()

Values=[]

#for loop 
for line in infile:
    line=line.strip()          #Strip off whitespace off each line end
    line=line.split(',')       #Split the variable off into individual string
    Year=line[0]               #Year
    Value=float(line[1])       #Temperature
    Values.append(Value)       #grow list     

infile.close()

openfile=open('MovingAve.csv','w')
openfile.write("Year,Value\n")

# Loop with the correct range
for row in range(index,len(Values)-index):
    year = 1880 + row
    year=str(year)          #Convert int to str 
    ave = sum(Values[row-index:row+index+1]) / (2*index+1)
    ave="{:.4f}\n".format(ave)     #Format the result to four decimal places
    ave=str(ave)            #Conver int to str
    openfile.write(year+','+ave) 
                             #This creates no whitespace between the results. only one comma
openfile.close()
    

#SacramentoTemps.csv
