import csv,math,random

simulationstep=1 #number of runs
samples=0
numberOfAttributes=8
numberOfClass=2
countlist=[]
classCountList=[0]*numberOfClass # classCountList[i] means how many datas with ith output are there

"""A 2D array,countlist[i][j]= number of examples of class i where j-th attribute is present,if attribute value range is in [1,5],it is denoted as absent;[6-10]--it is present"""

def buildCountList():

    for i in range(numberOfClass):
        temparray=[]
        for j in range(numberOfAttributes):
            temparray.append(0)  #initialize countlist[i][j] by 0
        countlist.append(temparray)

    print("This is count list\n")
    print(countlist)
    print(classCountList)
    #print("No of total samples is "+str(total_samples))

def parse_csv_file(filename,delim=' , '):

    
    with open(filename, 'r') as f:
        reader = csv.reader(f)
        your_list = list(reader)
    return your_list[1:]

       
    
class Example:

    def __init__(self,data):
        
        self.attribute_values=[int(x)-1 for x in data[:-1]]
        self.target_attribute=int(data[-1])

    def __str__(self):

        retstr=""
        for aval in self.attribute_values:
            retstr=retstr+" "+str(aval)

        retstr+=" targetvalue: "
        retstr+=str(self.target_attribute)

        return retstr

class Dataset:

    def __init__(self):

        self.examples=[]

    def __repr__(self):

        retstr="\nThe dataset is "+str(self.get_size())+" long:\n"

        for e in self.examples:
            retstr=retstr+str(e)+"\n";

        return retstr

    def divide_data(self):

        training_dataset=Dataset()
        test_dataset=Dataset()

        temp_examples=self.examples
        random.shuffle(temp_examples)

        training_data_size=int(0.8*self.get_size())

        training_dataset.examples=temp_examples[:training_data_size]
        test_dataset.examples=temp_examples[training_data_size:]

        return training_dataset,test_dataset
    def add_example(self,example):

        self.examples.append(example)

    def get_size(self):

        return len(self.examples)

    def is_all_same(self):

        base=self.examples[0].target_attribute
        allsame=True
        
        for e in self.examples:
            if e.target_attribute !=base:
                allsame=False
                break

        return allsame

    def get_plurality_value(self):

        p_benign=0
        p_malignant=0
       
        for example in self.examples:
            v=example.target_attribute
            #print(v)
            if v==0:
                p_benign+=1
            else:
                p_malignant+=1
        #print(p_benign,p_malignant)

        if p_benign>=p_malignant:
            return 0
        else:
            return 1
        
        
    def get_entropy(self):

        p_benign=0
        p_malignant=0
        total=0

        for example in self.examples:
            v=example.target_attribute
            #print(v)
            if v==0:
                p_benign+=1
            else:
                p_malignant+=1
            total+=1
        #print(p_benign,p_malignant)

        if p_benign==0 or p_malignant==0:
            return 0

        p_benign/=total
        p_malignant/=total
        

        entropy=-p_benign*math.log2(p_benign)-p_malignant*math.log2(p_malignant)

        return entropy

    def get_info_gain(self,attr_id):

        infogain=self.get_entropy()
        
        dataset_new=[]
        
        for i in range(0,10):
            dataset_new.append(Dataset())
        
        for example in self.examples:

            dataset_new[example.attribute_values[attr_id]].examples.append(example)

        expected_entropy=0.0    
        for i in range(0,10):
            #print(dataset_new[i])
            entro=dataset_new[i].get_entropy()
            #print(entro)
            expected_entropy+=((dataset_new[i].get_size())*(dataset_new[i].get_entropy()))/self.get_size()
        infogain-=expected_entropy
        return infogain
        





def train_naive_bayes(training_data):

    buildCountList()

    #print(total_samples)
    for example in training_data.examples:

      #  total_samples+=1
        attributes=example.attribute_values
        classOfOutput=example.target_attribute
        classCountList[classOfOutput]+=1  #i th class sample no increase
        for i in range(numberOfAttributes):

            #if attribute value lies in range [0-4],it is counted as 0,otherwise,for [5-9],it is counted as 1
            if(attributes[i]>4):
                countlist[classOfOutput][i]+=1
            
    
    
    print(countlist)
    print(classCountList)
    
def test_naive_bayes_single(test_example):

    samples=sum(x for x in classCountList)
    print(samples)

    print("This is actual data, the last no is the class\n")
    print(test_example)

    maxprobability=0.0
    resultclass=-1
     

    for i in range(numberOfClass):

        result=1.0 #calculated P(Ci|test_example) are stored in result

        attributes=test_example.attribute_values
        classOfOutput=test_example.target_attribute
        for j in range(numberOfAttributes):

            x=1.0
            #if attribute value lies in range [0-4],it is counted as 0,otherwise,for [5-9],it is counted as 1
            if(attributes[j]>4):

                #P(attribute-j|Class-i)
                x*=(countlist[i][j]) #Nj(i),number of samples of class i with attrib j present 
                x/=classCountList[i]
                
            else:
                #1-P(attribute-j|Class-i)
                
                x*=(countlist[i][j]) #Nj(i),number of samples of class i with attrib j present 
                x/=classCountList[i]
                x=1-x
                
            result*=x

        result*=(classCountList[i]/samples)

        print("probability of class "+str(i)+" is "+str(result))
        
        if(result>maxprobability):
            maxprobability=result
            resultclass=i


    return resultclass

def test_naive_bayes(test_data):

     for example in test_data.examples:

         predicted_result=test_naive_bayes_single(example)
         print("The example is classified as class "+str(predicted_result))
    
def apply_naive_bayes_classifier(filename):
    
    parsed_data=parse_csv_file(filename)
    dataset=Dataset()
    for data in parsed_data[:]:
        #print(data)
            
        e=Example(data)
        #print((e))

        dataset.add_example(e)

    
    training_data_stat=[0]*7
    test_data_stat=[0]*7
    
    for i in range(0,simulationstep):
        training_dataset,test_dataset=dataset.divide_data()
        AttributeList=[i for i in range(0,8)]
        train_naive_bayes(training_dataset)
        test_naive_bayes(test_dataset)
             
    
if __name__ == "__main__":
    # execute only if run as a script
    #generate_statistics("assignment1_data_set.csv")
    apply_naive_bayes_classifier("assignment1_data_set.csv")





https://cse.google.com/?cx=013315504628135767172%3Ad6shbtxu-uo&cof=FORID%3A10&ie=UTF-8&q=Hello#gsc.tab=0&gsc.q=Hello&gsc.page=1
    
