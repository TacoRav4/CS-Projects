# Part 3
# Jason Zhang
#
# Reading the data into a list

#Input
file=input('Temperature anomaly filename:')
infile=open(file)

#Ignore the header
infile.readline()

Values=[]

#for loop 
for line in infile:
    line=line.strip()          #Strip off whitespace off each line end
    line=line.split(',')       #Split the variable off into individual string
    Year=line[0]               #Year
    Value=float(line[1])       #Temperature
    Values.append(Value)       #this makes the variables on a horizontal line
    
             


print(Values) 
infile.close()



#SacramentoTemps.csv
