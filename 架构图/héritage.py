import os
import html

class CppClass:
    def __init__(self,className) -> None:
        self.attributs=[]
        self.méthodes=[]
        self.className=className
    def addAttribut(self,attribut):
        self.attributs.append(attribut)

    def addMéthode(self,attribut):
        self.méthodes.append(attribut)

    def generateAttributs(self):
        string="<b>Attributs</b>"
        for attribut in self.attributs:
            string+=f"<br/>{html.escape(attribut)}"
        return string
    
    def generateMéthodes(self):
        string="<b>Méthodes</b>"
        for méthode in self.méthodes:
            string+=f"<br/>{html.escape(méthode)}"
        return string
    
classes=[]

Journey=CppClass("Journey")
classes.append(Journey)

for i in ["const char *_from","const char *_to","unsigned int refCount = 0"]:
    Journey.addAttribut(i)

for i in ['virtual void show(void) const','Journey(const char *start = "", const char *end = "")',"friend std::ostream &operator<<(std::ostream &os, const Journey &journey)","virtual ~Journey()"]:
    Journey.addMéthode(i)



SimpleJourney=CppClass("SimpleJourney")
classes.append(SimpleJourney)

for i in ["const char *_transportMethod"]:
    SimpleJourney.addAttribut(i)

for i in ['SimpleJourney(const char *start = "", const char *end = "",const char *transportMethod = "")','virtual ~SimpleJourney()','void show(void) const']:
    SimpleJourney.addMéthode(i)



Journeys=CppClass("Journeys")
classes.append(Journeys)

for i in ['LinkedList<Journey> journeyLinkedList',]:
    Journeys.addAttribut(i)

for i in ['friend std::ostream &operator<<(std::ostream &os, const Journeys &journeys)','void add(Journey *pjourney)',"void show(const char sep = '\|') const"]:
    Journeys.addMéthode(i)



Catalog=CppClass("Catalog")
classes.append(Catalog)

for i in ['PathNode pathRoot','']:
    Catalog.addAttribut(i)

for i in ['friend std::ostream &operator<<(std::ostream &os, const Catalog &Catalog)','void search(const char *const from, const char *const to, PathNode *pathHead = nullptr)']:
    Catalog.addMéthode(i)



PathNode=CppClass("PathNode")
classes.append(PathNode)

for i in ['Journey *pjourney','PathNode *lastPathNode','LinkedList<PathNode> nextPathNodes','unsigned int refCount = 0']:
    PathNode.addAttribut(i)

for i in ['']:
    PathNode.addMéthode(i)


CompositeJourney=CppClass("CompositeJourney")
classes.append(CompositeJourney)

for i in ['']:
    CompositeJourney.addAttribut(i)

for i in ['int add(Journey *journey, bool check = true)','friend std::ostream &operator<<(std::ostream &os, const CompositeJourney &compositeJourney)','void show(void) const']:
    CompositeJourney.addMéthode(i)





l=""
for _class in classes:
    l+='\n\n\t'+_class.className+' [label = <{<b>'+_class.className+'</b>  |'+_class.generateAttributs()+'|'+_class.generateMéthodes()+"}>;];\n"





s="""
digraph graphname {
    
	node [
		fontname="Helvetica,Arial,sans-serif"
		shape=record
		style=filled
		fillcolor=gray95
	]
    

    """+l+"""
    CompositeJourney; 
    Journeys;
    Catalog;
    
    Catalog -> Journeys;
    CompositeJourney -> Journeys;
    CompositeJourney -> Journey;
    SimpleJourney -> Journey;
    
}
"""

with open('héritage.dot', 'w') as file:
    file.write(s)
