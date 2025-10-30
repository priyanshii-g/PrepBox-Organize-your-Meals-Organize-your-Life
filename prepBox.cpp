#include <bits/stdc++.h>


using namespace std;
class Recipe
{
    public:
   // int servings;
    string name;
    int cuiCode;//stored as string in RecipeFromFIle
    string cuisine;
    int difficulty;//string
    int prepTime;
    int cookTime;
    //int category: brek, lunch,dinner
    string description;
    string instructions;
    int serving;
    array<double,5> nutriVal;
    unordered_map <string,pair<double,string>> ingredients;

    // Recipe(){nutriVal={0};}
    Recipe(): name(""), cuiCode(0), cuisine(""), difficulty(0),
          prepTime(0), cookTime(0), ingredients({}),
          description(""), instructions("") {}
   Recipe(string n, int cc, string c, int d, int prep, int cook,
       unordered_map<string, pair<double, string>> in, string desc, string instruct
       )
    : name(n), cuiCode(cc), cuisine(c), difficulty(d),
      prepTime(prep), cookTime(cook), ingredients(in),
      description(desc), instructions(instruct) { nutriVal=nutritionalValue();}
    string get_name()
    {
        return name;
    }
    int get_cuiCode()
    {
        return cuiCode;
    }
    int get_difficulty()
    {
        return difficulty;
    }
    int PrepTimeinMins() //returns a single value for simplified sorting
    {
        return prepTime;
    }
    int CookTimeinMins() //returns a single value for simplified sorting
    {
        return cookTime;
    }
    void displaySRecipe()
    {
        int h=prepTime/60;
        cout<<"NAME:         "<<name<<endl;
        cout<<"CUISINE:      "<<cuisine<<endl;
        if(h!=0)
        cout<<"PREPTIME:     "<<h<<" hours, "<<(prepTime%60)<<" minutes"<<endl;
        else
        cout<<"PREPTIME:     "<<(prepTime%60)<<" minutes"<<endl;
        h=cookTime/60;
        if(h!=0)
        cout<<"COOKTIME:     "<<h<<" hours, "<<(cookTime%60)<<" minutes"<<endl;
        else
        cout<<"COOKTIME:     "<<(cookTime%60)<<" minutes"<<endl;
        cout<<"DESCRIPTION:  "<<endl;
        cout<<description;
    }
    void detailed_recipe(int n)
    {
        int h=prepTime/60;
        cout<<"NAME:            "<<name<<endl;
        cout<<"INGREDIENTS:     "<<endl;
        for(const auto& item : ingredients)
        {
           cout<<item.first<<"\t"<<item.second.first<<"  "<<item.second.second;
        }
        cout<<"CUISINE:         "<<cuisine<<endl;
        if(h!=0)
        cout<<"PREPTIME:        "<<h<<" hours, "<<(prepTime%60)<<" minutes"<<endl;
        else
        cout<<"PREPTIME:        "<<(prepTime%60)<<" minutes"<<endl;
        h=cookTime/60;
        if(h!=0)
        cout<<"COOKTIME:        "<<h<<" hours, "<<(cookTime%60)<<" minutes"<<endl;
        else
        cout<<"COOKTIME:        "<<(prepTime%60)<<" minutes"<<endl;
        cout<<"INSTRUCTIONS: "<<endl;
        cout<<instructions;
       cout<<"NUTRITIONAL VALUES: "<<endl;
      cout<<"Protein: "<<nutriVal[0]<<" gm"<<endl;
      cout<<"Carbs: "<<nutriVal[1]<<" gm"<<endl;
      cout<<"Fats: "<<nutriVal[2]<<" gm"<<endl;
        cout<<"Fiber: "<<nutriVal[3]<<" gm"<<endl;
        cout<<"Calories: "<<nutriVal[4]<<" cal"<<endl;
    }
array<double,5> nutritionalValue()
{

unordered_map<string,array<double,5>>nv;//nutritional value data for 1 tsp unless mentioned (1pc/ 1gm (in some cases as mentioned))
//{protein,carbs,fats,fiber,calories} everything in gm except calories (Cal)
nv["tomatoes"]={1.1,4.4,0.3,2.1,25}; //1 pc
nv["milk"]={0.5/3,0.7/3,0.6/3,0.0,10/3};
nv["paneer"]={0.2,0,0.2,0,3};//1 gm
nv["bell peppers"]={1,5.5,0.2,2.0,24};//1 pc
nv["onions"]={1.2,10.3,0.1,1.9,44};
nv["ginger-garlic paste"]={0.1,0.4,0,0,2};
nv["fresh cream"]={0.1,0.2,1.3,0,12};
nv["oil"]={0,0,4.5,0,41};
nv["dosa batter"]={10.6/48,67.4/48,0.8/48,3.7/48,319/48};
nv["potatoes"]={3.4,48.1,0.2,3.6,207};//1 pc
nv["green chilies"]={0.2,0.2,0,0.1,1};//1 pc
nv["curry leaves"]={0.1,0.4,0,0.3,2};//1 pc
nv["mustard seeds"]={0.6,0.7,1.1,0.4,15};
nv["turmeric powder"]={0.2,1.4,0.2,0.5,8};
nv["lemon juice"]={0,0.4,0,0,1};
nv["sugar"]={0,3,0,0,12};
nv["water"]={0,0,0,0,0};
nv["milk powder"]={0.9,2.6,0.7,0,20};
nv["maida"]={0.3,1.9,0,0.1,9};
nv["baking powder"]={0,1.3,0,0,2};
nv["ghee"]={0,0,3.1,0,28};
nv["cardamom"]={0.1/5,0.4/5,0,0.2/5,2/5};//1 pc
nv["besan"]={1.3/3,3.3/3,0.4/3,0.6/3,22/3};
nv["curd"]={0.5/3,0.5/3,0.6/3,0,9/3};
nv["basmati rice"]={12.1/48,144/48,0,2/48,641/48};
nv["chicken"]={0.2,0,4.4/140,0,1};//1 gm
nv["biryani masala"]={0,1.6,0.2,0.5,9};
nv["mint leaves"]={1.2/48,1.5/48,0.2/48,1.6/48,12/48};//1 tsp
nv["yogurt"]={0.5/3,0.7/3,0.5/3,0,9/3};
nv["red chili powder"]={0.4,1.4,0.4,0.9,8};
nv["cumin powder"]={0.4,0.9,0.5,0.2,8};
nv["cashews"]={0.3,0.3,0.7,0.1,8};//1 pc
nv["cream"]={0.1,0.2,1.3,0,12};
nv["butter"]={0,0,3.8,0,34};
nv["all-purpose flour"]={0.3,1.9,0,0.1,9};
nv["yeast"]={1.9,1.7,0.2,0.9,15};
nv["garlic"]={0.2,1,0,0.1,4};//1 clove
nv["cilantro"]={0.4/48,0.6/48,0.1/48,0.5/48,4/48};
nv["cardamom powder"]={0.2,0.9,0.1,0.5,5};
nv["toor dal"]={2.8/3,7.1/3,0.2/3,1.1/3,41/3};
nv["ginger"]={0.1,0.3,0,0.1,1};//1 inch
nv["cumin seeds"]={0.4,0.8,0.3,0.6,7};
nv["capsicum"]={1,5.5,0.2,2,24};//1 pc
nv["green peas"]={10.4/48,23.1/48,0.2/48,12.5/48,135/48};
nv["pav bhaji masala"]={0.2,1,0.1,0.1,6};
nv["garlic paste"]={0.2/3,1.1/3,9.3/3,0.1/3,88/3};
nv["pav buns"]={5.5,36,6.4,2.5,224};//1 pc
nv["lemon"]={0.7,7.4,0.6,1.9,38};//1 pc
nv["chickpeas"]={2.4/3,7.6/3,0.8/3,2.2/3,46/3};
nv["chole masala"]={10.5/48,37.5/48,14.4/48,9.6/48,315/48};
nv["wheat flour"]={0.9/3,5.2/3,0.1/3,0.8/3,26/3};
nv["coriander leaves"]={0.5/48,1/48,0.1/48,0.7/48,7/48};
nv["kidney beans"]={2.6/3,7/3,0.2/3,2.9/3,40/3};
nv["rice"]={4.3/48,44.4/3,0.6/48,0.8/48,200/48};
nv["garam masala"]={0.7,1.7,0.6,0,15};
nv["whole black lentils"]={3/3,7.7/3,0.1/3,1.3/3,43/3};
nv["red kidney beans"]={2.6/3,7/3,0.2/3,2.9/3,40/3};
nv["flattened rice (poha)"]={6.2/48,72.7/48,1.1/48,0.7/48,325/48};
nv["peanuts"]={2.3/3,1.5/3,4.4/3,0.8/3,51/3};
nv["cooked rice"]={4.3/48,44.4/48,0.6/48,0.8/48,200/48};
nv["minced mutton"]={0.2,0,0.2,0,3};//1 gm
nv["roasted gram flour"]={1/3,4.8/3,0.6/3,0.8/3,28/3};
nv["parathas"]={4.3,23.2,4,3.5,139};
nv["pizza base"]={9.7,54.8,7.2,1.9,323};
nv["mozzarella cheese"]={25.7/48,4.5/48,19.2/48,0,294/48};
nv["tomato sauce"]={2.9/48,13/48,0.7/48,3.7/48,59/48};
nv["red chili flakes"]={0.3,0.6,0.1,0,5};
nv["oregano"]={0.2,1.3,0.1,0.8,5};
nv["olive oil"]={0,0,4.5,0,41};
nv["fettuccine pasta"]={0.1,0.8,0,0,4};//1 gm
nv["parmesan cheese"]={40.4/48,3.6/48,29.2/48,0,443/48};
nv["black pepper"]={0.3,1.4,0.2,1,9};
nv["parsley"]={0.2/3,0.5/3,0,0.1/3,3/3};
nv["spaghetti"]={0.13,0.7,0.04,0.04,3.6};//1 gm
nv["ground beef"]={0.2,0,0.13,0,2};//1 gm
nv["carrots"]={0.6,6.5,0.1,2.7,29};//1 pc
nv["celery"]={0.1,0.5,0,0.3,3};//1 stalk
nv["tomato puree"]={4.1/48,22.5/48,0.5/48,4.8/48,95/48};
nv["lasagna sheets"]={2.4,14.2,0.2,0.7,69};//1 pc
nv["basil"]={0.9,1.8,1.1,1.8,20};
nv["baguette"]={17.9,102.5,3.8,4.1,525};
nv["ladyfinger biscuits"]={0.08,0.52,0.05,0.01,2.8};
nv["mascarpone cheese"]={0.07,0,0.47,0,4.3};
nv["eggs"]={5.5,0.5,4.7,0,68};
nv["coffee"]={6.4/48,20.1/48,8.2/48,1.2/48,180/48};
nv["cocoa powder"]={0.6,1.4,0.3,0.9,11};
nv["vanilla extract"]={0,0.5,0,0,12};
nv["ricotta cheese"]={27.9/48,7.5/48,32.2/48,0,432};
nv["spinach"]={0.6/48,0.9/48,0.2/48,0.8/48,8/48};
nv["nutmeg"]={0.1,1.1,0.8,0.5,12};
nv["pizza dough"]={17.1,100.8,9.2,3.8,564};
nv["basil leaves"]={0.1/3,0.1/3,0,0.1/3,1/3};
nv["egg yolks"]={2.7,0.6,4.5,0,55};
nv["taco shells"]={0.9,7.8,3.5,0.4,67};//1 pc
nv["lettuce"]={0.8/48,0.9/48,0.1/48,0.5/48,8/48};
nv["cheddar cheese"]={28.1/48,1.5/48,37.5/48,0,455/48};
nv["sour cream"]={0.4/3,0.7/3,2.7/3,0,28/3};
nv["taco seasoning"]={0,1.5,0,0.5,8};
nv["flour tortillas"]={2.2,17,1.1,2.4,83};//1 pc
nv["black beans"]={42/48,126/48,1.8/48,32/48,678/48};
nv["guacamole"]={0.1,0.1,0.6,0.3,6};
nv["cinnamon powder"]={0.1,2.1,0,1.4,6};
nv["masa harina"]={12/48,84/48,4/48,8/48,400/48};
nv["chicken broth"]={5/48,0.9/48,1.5/48,0,40/48};
nv["pulled chicken"]={0.11,0.1,0.1,0.03,1.8};
nv["pork"]={0.19,0,0.04,0,1.1};
nv["chili sauce"]={0.2/3,5.7/3,0.1/3,0,24/3};
nv["lard"]={0,0,12.8/3,0,115/3};
nv["avocados"]={5.9,3.5,27.9,13.5,290};
nv["jalapeño"]={0.2,1,0.2,0.6,6};//1 pc
nv["lime juice"]={0.1/3,1/3,0,0.1/3,3/3};
nv["corn tortillas"]={2.2,17,1.1,2.4,83};//1 pc
nv["shredded chicken"]={0.2,0,4.4/140,0,1};//1 gm
nv["enchilada sauce"]={3/48,18.2/48,9.8/48,4.3/48,161/48};
nv["tortilla chips"]={0.07,0.67,0.22,0.05,5};
nv["olives"]={0.1/3,0.5/3,0.9/3,0.3/3,10/3};
nv["salsa"]={0.1,0.3,0,0.1,1};
nv["bread rolls"]={4.3,28.6,8.9,1.9,212};//1 pc
nv["chorizo"]={0.24,0.02,0.38,0,4.6};
nv["guajillo chili sauce"]={0.2/3,5.7/3,0.1/3,0,24/3};
nv["cheese"]={27.2/48,7.1/48,28.4/48,0,393/48};
nv["vegetable oil"]={0,0,4.5,0,40};
nv["dumpling wrappers"]={0.8,5.6,0.1,0.3,26};//1 pc
nv["minced pork"]={0.19,0,0.04,0,1.1};
nv["cabbage"]={1.3/48,3.2/48,0.1/48,2/48,19/48};
nv["spring onions"]={0.3,1.1,0,0.4,5};
nv["soy sauce"]={0.6,0.3,0,0.1,4};
nv["sesame oil"]={0,0,4.5,0,40};
nv["schezwan sauce"]={0.2,1.6,0.4,0,11};
nv["green beans"]={1.8/48,7/48,0.2/48,2.7/48,31/48};
nv["noodles"]={0.04,0.22,0.05,0.01,1.4};
nv["spring roll wrappers"]={0.8,4.6,0.1,0.2,23};
nv["shredded cabbage"]={1.3/48,3.2/48,0.1/48,2/48,19/48};
nv["green onions"]={0.3,1.1,0,0.4,5};
nv["shiitake mushrooms"]={1.6/48,4.8/48,0.4/48,1.8/48,24/48};
nv["cauliflower florets"]={2.2/48,6.7/48,1.1/48,2.7/48,43/48};
nv["cornflour"]={0,2.9,0,0,12};
nv["bao buns"]={5.9,27.3,9.4,2.6,215};
nv["honey"]={0,5.6,0,0,22};
nv["cucumber"]={1.3,7.3,0.2,1,30};
nv["hoisin sauce"]={0.2,2.3,0.2,0.2,12};
nv["firm tofu"]={0.14,0.05,0.07,0,1.4};// 1 gm
nv["broccoli"]={2.6/48,6.1/48,0.3/48,2.4/48,31/48};
nv["carrot"]={0.6,6.5,0.1,2.7,29};//1 pc
nv["ramen noodles"]={25,181.3,2.8,0,850};
nv["vegetable broth"]={0,3.1/48,0,0,15/48};
nv["miso paste"]={0.5,1.8,0.2,0,11};
nv["egg"]={5.5,0.5,4.7,0,68};
nv["nori (seaweed)"]={0.5,0.5,0,0.5,5};
nv["chicken breast"]={0.23,0,0.03,0,1.2};
nv["dried red chilies"]={0.1,0.5,0,0.1,2};//1 pc

    unordered_map<string,pair<double,string>>::iterator it;
    for(int i=0;i<5;i++)
         nutriVal[i]=0;

    for(it=ingredients.begin();it!=ingredients.end();it++)
    {
        unordered_map<string,array<double,5>>:: iterator ing=nv.find(it->first);
        if(ing!=nv.end())
        {
            if(it->second.second=="tsp" || it->second.second=="pc" || it->second.second=="pcs" || it->second.second=="gm" || it->second.second=="cloves" || it->second.second=="inch" || it->second.second=="stalk"|| it->second.second=="bundles" || it->second.second=="stalks" || it->second.second=="sheets")
            {
                for(int i=0;i<5;i++)
                {
                    nutriVal[i]+=(ing->second)[i];
                }
            }
            else if(it->second.second=="tbsp")
            {
                for(int i=0;i<5;i++)
                {
                    nutriVal[i]+=(ing->second)[i]*3;
                }
            }
            else if(it->second.second=="ml")
            {
                for(int i=0;i<5;i++)
                {
                    nutriVal[i]+=(ing->second)[i]*0.203;
                }
            }
            else if(it->second.second=="liter")
            {
                for(int i=0;i<5;i++)
                {
                    nutriVal[i]+=(ing->second)[i]*203;
                }
            }
            else if(it->second.second=="cup" || it->second.second=="cups")
            {
                for(int i=0;i<5;i++)
                {
                    nutriVal[i]+=(ing->second)[i]*48.7;
                }
            }
           // else
               // cout<<it->second.second<<" unit not found!"<<endl;


        }
       // else
           // cout<<it->first<<" not found in nutritional value dataset"<<endl;


    }
    return nutriVal;
}
};
void MergeP(vector <Recipe> arr, int s, int mid, int e) //Merge Sort Code for sorting by Prep Time
{
    int i=0,j=0,la=mid-s+1,lb=e-mid,k;
    Recipe a[la],b[lb];
    for(int i=0; i<la; i++)
    {
        a[i]=arr[s+i];
    }
    for(int j=0; j<lb; j++)
    {
        b[j]=arr[mid+1+j];
    }
    i=0,j=0,k=0;
    while(i!=la&&j!=lb)
    {
        if(a[i].PrepTimeinMins()<b[j].PrepTimeinMins())
            arr[k++]=a[i++];
        else
            arr[k++]=b[j++];
    }
    while(i!=la)
    {
        arr[k++]=a[i++];
    }
    while(j!=lb)
    {
        arr[k++]=b[j++];
    }
}
void MergeSortP(vector <Recipe> arr, int s, int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        MergeSortP(arr,s,mid);
        MergeSortP(arr,mid+1,e);
        MergeP(arr,s,mid,e);
    }
}
void MergeC(vector <Recipe> arr, int s, int mid, int e) //Merge Sort Code for sorting by Cooking Time
{
    int i=0,j=0,la=mid-s+1,lb=e-mid,k;
    Recipe a[la],b[lb];
    for(int i=0; i<la; i++)
    {
        a[i]=arr[s+i];
    }
    for(int j=0; j<lb; j++)
    {
        b[j]=arr[mid+1+j];
    }
    i=0,j=0,k=0;
    while(i!=la&&j!=lb)
    {
        if(a[i].CookTimeinMins()<b[j].CookTimeinMins())
            arr[k++]=a[i++];
        else
            arr[k++]=b[j++];
    }
    while(i!=la)
    {
        arr[k++]=a[i++];
    }
    while(j!=lb)
    {
        arr[k++]=b[j++];
    }
}
void MergeSortC(vector <Recipe> arr, int s, int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        MergeSortC(arr,s,mid);
        MergeSortC(arr,mid+1,e);
        MergeC(arr,s,mid,e);
    }
    else
    {
        for(int i=0;i<arr.size();i++)
        {
            arr[i].displaySRecipe();
        }
    }
    }void displayCurr(vector <Recipe> v) //default display code for the recipes passing the given filter
{
//    cout<<"The recipes as per the given filters are: ";
    for(int i=0; i<v.size(); i++)
    {
        v[i].displaySRecipe();
        cout<<endl;
    }
}
class playList{
    public:
    int pnum;
    string pname;
    string desc;
    vector <Recipe> rc;
    playList(string nm,string ds)
    {
        pname=nm;
        desc=ds;
    }
    void dispPlay()
    {
        cout<<"Playlist Number: "<<pnum<<endl;
        cout<<"Playlist name: "<<pname<<endl;
        cout<<"Description: "<<desc<<endl;
    }
};
struct RecipeNode// Node for each node for further recipe nodes
{
    Recipe data;
    RecipeNode *lc, *rc;
    int height;
    RecipeNode(Recipe r):data(r),lc(NULL),rc(NULL),height(1){}
};




class RecipeAVL
{

    public:
    RecipeNode* root;
    int height(RecipeNode* n)
    {
        if(!n)
            return 0;
        else
            return n->height;
    }




    int balance(RecipeNode* n)
    {
        return n?height(n->lc)-height(n->rc):0;
    }
    RecipeNode* rr(RecipeNode* r)
    {
        RecipeNode* a=r->lc;
        RecipeNode* b=a->rc;
        a->rc=r;
        r->lc=b;
        r->height=1+max(height(r->lc), height(r->rc));
        a->height=1+max(height(a->lc), height(a->rc));
        return a;
    }




    RecipeNode* lr(RecipeNode* r)
    {
        RecipeNode* a=r->rc;
        RecipeNode* b=a->lc;
        a->lc=r;
        r->rc=b;
        r->height=1+max(height(r->lc), height(r->rc));
        a->height=1+max(height(a->lc), height(a->rc));
        return a;
    }




    RecipeNode* insertR(RecipeNode* node, Recipe& reci)
    {
        if(!node)
            return new RecipeNode(reci);
         string recNam=reci.get_name();
        string nodeNam=node->data.get_name();
        if(recNam < nodeNam)
            node->lc= insertR(node->lc, reci);
        else if(recNam > nodeNam)
            node->rc= insertR(node->rc, reci);
        else
            return node;

        node->height=1+max(height(node->lc), height(node->rc));
        int bal=balance(node);
        if(bal>1 && recNam<nodeNam)
            return rr(node);
        if(bal<-1 && recNam>nodeNam)
            return lr(node);
        if(bal>1 && recNam>nodeNam)
        {node->lc=lr(node->lc);
            return rr(node);}
        if(bal<-1 && recNam<nodeNam)
        {node->rc=rr(node->rc);
            return lr(node);}
        return node;
    }
    RecipeNode* find(string n)
    {
        return find(root,n);
    }
    RecipeNode* find(RecipeNode* node, string n)
    {
        if(!node||node->data.get_name()==n)return node;
        if(n<node->data.get_name())
            return find(node->lc, n);
        return find(node->rc, n);
    }








    RecipeNode* inSucc(RecipeNode* node)
    {
        RecipeNode* curr=node;
        while(node->lc)
            curr=curr->lc;
        return curr;
    }




    RecipeNode* deleteR(RecipeNode* node, Recipe& reci)
    {
        if(!node)
            return node;
        string recNam=reci.get_name();
        string nodeNam=node->data.get_name();
        if(recNam<nodeNam)
            node->lc=deleteR(node->lc, reci);
        else if(recNam>nodeNam)
            node->rc=deleteR(node->rc, reci);
        else
        {
            if(!node->lc||!node->rc)
            {
                RecipeNode* tmp=node->lc?node->lc:node->rc;
                delete node;
                return tmp;
            }
            RecipeNode* temp=inSucc(node->rc);
            node->data=temp->data;
            node->rc= deleteR(node->rc, temp->data);
        }




        node->height=1+max(height(node->lc), height(node->rc));
        int bal= balance(node);
        if(bal>1 && balance(node->lc)>=0)
            return rr(node);
        if(bal>1 && balance(node->lc)<0)
            {
                node->lc=lr(node->lc);
                return rr(node);
            }
        if(bal<-1 && balance(node->rc)<=0)
            return lr(node);
        if(bal<-1 && balance(node->rc)>0)
        {
            node->rc= rr(node->rc);
            return lr(node);
        }
        return node;
    }
    void inOrder()
    {
        inOrder(root);
    }
    void inOrder(RecipeNode* node)
    {
        if(node)
        {
            inOrder(node->lc);
            node->data.displaySRecipe();
            inOrder(node->rc);
        }
    }
    void displayRecipe(string name) {
    RecipeNode* node = find(name);

    if (node) {
        node->data.displaySRecipe();
    } else {
        cout << "Recipe not found!" << endl;
    }
}
};




struct TimeNode{
    int ul;
    vector <Recipe> r;
    TimeNode* lc;
    TimeNode* rc;
    int height;
    TimeNode(int l)
    {
        ul=l;
        lc=nullptr,rc=nullptr;
        height=0;
    }
};




class TimeAVL
{
    public:
    TimeNode* root;
    TimeAVL()
    {
        root=nullptr;
    }
    int height(TimeNode* n)
    {
        if(!n)
            return 0;
        else
            return n->height;
    }
    int balance(TimeNode* n)
    {
        return n?height(n->lc)-height(n->rc):0;
    }
    TimeNode* rr(TimeNode* r)
    {
        TimeNode* a=r->lc;
        TimeNode* b=a->rc;
        a->rc=r;
        r->lc=b;
        r->height=1+max(height(r->lc), height(r->rc));
        a->height=1+max(height(a->lc), height(a->rc));
        return a;
    }
    TimeNode* lr(TimeNode* r)
    {
        TimeNode* a=r->rc;
        TimeNode* b=a->lc;
        a->lc=r;
        r->rc=b;
        r->height=1+max(height(r->lc), height(r->rc));
        a->height=1+max(height(a->lc), height(a->rc));
        return a;
    }
    TimeNode* insertT(int lmt){return insertT(root, lmt);}
    TimeNode* insertT(TimeNode* node, int lmt)
    {
        if(!node)
            return new TimeNode(lmt);
            int ul=node->ul;
        if(lmt < ul)
            node->lc= insertT(node->lc, lmt);
        else if(lmt > ul)
            node->rc= insertT(node->rc, lmt);
        else
            return node;

        node->height=1+max(height(node->lc), height(node->rc));
        int bal=balance(node);
        if(bal>1 && lmt<ul)
            return rr(node);
        if(bal<-1 && lmt>ul)
            return lr(node);
        if(bal>1 && lmt>ul)
        {node->lc=lr(node->lc);
            return rr(node);}
        if(bal<-1 && lmt<ul)
        {node->rc=rr(node->rc);
            return lr(node);}
        return node;
    }




    TimeNode* inSucc(TimeNode* node)
    {
        TimeNode* curr=node;
        while(node->lc)
            curr=curr->lc;
        return curr;
    }

    TimeNode* deleteT(TimeNode* node, int lmt) {
        if (!node)
            return node;




        if (lmt < node->ul)
            node->lc = deleteT(node->lc, lmt);
        else if (lmt > node->ul)
            node->rc = deleteT(node->rc, lmt);
        else {
            if (!node->lc || !node->rc) {
                TimeNode* temp = node->lc ? node->lc : node->rc;
                delete node;
                return temp;
            }
            TimeNode* temp = inSucc(node->rc);
            node->ul = temp->ul;
            node->rc = deleteT(node->rc, temp->ul);
        }




        node->height = 1 + max(height(node->lc), height(node->rc));
        int bal = balance(node);
        if (bal > 1 && balance(node->lc) >= 0)
            return rr(node);
        if (bal > 1 && balance(node->lc) < 0) {
            node->lc = lr(node->lc);
            return rr(node);
        }
        if (bal < -1 && balance(node->rc) <= 0)
            return lr(node);
        if (bal < -1 && balance(node->rc) > 0) {
            node->rc = rr(node->rc);
            return lr(node);
        }




        return node;
    }
    void insertRecipe(int lmt, Recipe rec)
    {
        TimeNode* node = findNode(root, lmt);
        if (node)
            node->r.push_back(rec);
        else
        {
            root = insertT(root, lmt);
            node = findNode(root, lmt);
            if(node)
                node->r.push_back(rec);
        }
    }
    TimeNode* findNode(TimeNode* node, int lmt)
    {
        if(!node)
            return nullptr;
        if(node->ul==lmt)
            return node;
        if(lmt<node->ul)
            return findNode(node->lc, lmt);
        return findNode(node->rc, lmt);
    }
    void displayRecipesInRange(TimeNode* node, int startTime, int endTime)
{
    if (!node) return;




    // Traverse left subtree if range overlaps
    if (startTime < node->ul)
        displayRecipesInRange(node->lc, startTime, endTime);




    // Print current node's recipes if in range
    if (node->ul >= startTime && node->ul <= endTime) {
        cout << "Time: " << node->ul << endl;
        for (Recipe recipe : node->r) {
            recipe.displaySRecipe();
        }
    }




    // Traverse right subtree if range overlaps
    if (endTime > node->ul)
        displayRecipesInRange(node->rc, startTime, endTime);
}




// Wrapper function for specific range
void displayRange(int startTime, int endTime)
{
    displayRecipesInRange(root, startTime, endTime);
}




// Function to display recipes for a specific time
void displaySpecificTime(int time)
{
    TimeNode* node = findNode(root, time);
    if (!node) {
        cout << "No recipes found for time: " << time << endl;
        return;
    }
    cout << "Time: " << node->ul << endl;
    for (const Recipe& recipe : node->r) {
        cout << "- Recipe: " << recipe.name << ", Difficulty: " << recipe.difficulty << endl;
    }
}




};








struct CuisineNode
{
    string cuiName;
    int cuiCode;
    RecipeAVL recipes;
    CuisineNode* lc, *rc;
    int height;
    CuisineNode(int c):cuiCode(c),lc(NULL),rc(NULL),height(1){}
    CuisineNode(string n, int c):cuiName(n),cuiCode(c),lc(NULL),rc(NULL),height(1){}
};
class CuisineAVL
{
    public:
    CuisineNode* root;
    int height(CuisineNode* n)
    {
        if(!n)
            return 0;
        else
            return n->height;
    }




    int balance(CuisineNode* n)
    {
        return n?height(n->lc)-height(n->rc):0;
    }
    CuisineNode* rr(CuisineNode* r)
    {
        CuisineNode* a=r->lc;
        CuisineNode* b=a->rc;
        a->rc=r;
        r->lc=b;
        r->height=1+max(height(r->lc), height(r->rc));
        a->height=1+max(height(a->lc), height(a->rc));
        return a;
    }




    CuisineNode* lr(CuisineNode* r)
    {
        CuisineNode* a=r->rc;
        CuisineNode* b=a->lc;
        a->lc=r;
        r->rc=b;
        r->height=1+max(height(r->lc), height(r->rc));
        a->height=1+max(height(a->lc), height(a->rc));
        return a;
    }
    CuisineNode* insertR(int cuiCode){return insertR(root, cuiCode);}
    CuisineNode* insertR(CuisineNode* node, int cuiCode)
    {
        if(!node)
            return new CuisineNode(cuiCode);
        int nodeNam=node->cuiCode;
        if(cuiCode < nodeNam)
            node->lc= insertR(node->lc, cuiCode);
        else if(cuiCode > nodeNam)
            node->rc= insertR(node->rc, cuiCode);
        else
            return node;

        node->height=1+max(height(node->lc), height(node->rc));
        int bal=balance(node);
        if(bal>1 && cuiCode<nodeNam)
            return rr(node);
        if(bal<-1 && cuiCode>nodeNam)
            return lr(node);
        if(bal>1 && cuiCode>nodeNam)
        {node->lc=lr(node->lc);
            return rr(node);}
        if(bal<-1 && cuiCode<nodeNam)
        {node->rc=rr(node->rc);
            return lr(node);}
        return node;
    }




    CuisineNode* find(CuisineNode* node, int c)
    {
        if(!node||node->cuiCode==c)return node;
        if(c<node->cuiCode)
            return find(node->lc, c);
        return find(node->rc, c);
    }
    CuisineNode* inSucc(CuisineNode* node)// no need
    {
        CuisineNode* curr=node;
        while(node->lc)
            curr=curr->lc;
        return curr;
    }




    void inOrder(CuisineNode* node)
    {
        if(node)
        {
            inOrder(node->lc);
            cout<<node->cuiName<<endl;
            node->recipes.inOrder();
            inOrder(node->rc);
        }
    }




    void recipeDel(RecipeNode* node)
    {
        if(!node)return;
        recipeDel(node->lc);
        recipeDel(node->rc);
        delete node;
    }




    CuisineNode* CuisineDel(CuisineNode* node, int c)
    {
        if(!node) return NULL;
        if(c<node->cuiCode)
        node->lc=CuisineDel(node->lc, c);
        else if(c>node->cuiCode)
        node->rc=CuisineDel(node->rc, c);
        else
        {
            recipeDel(node->recipes.root);
            delete node;
            return NULL;
        }
        return node;
    }
};




void recipeDel(RecipeNode* node)
    {
        if(!node)return;
        recipeDel(node->lc);
        recipeDel(node->rc);
        delete node;
    }
CuisineNode* CuisineDel(CuisineNode* node, int c)
{
    if(!node) return NULL;
    if(c<node->cuiCode)
    node->lc=CuisineDel(node->lc, c);
    else if(c>node->cuiCode)
    node->rc=CuisineDel(node->rc, c);
    else
    {
        recipeDel(node->recipes.root);
        delete node;
        return NULL;
    }
    return node;
}




class PrepBox
{
public:
    vector <Recipe> rcp;
    CuisineAVL cuiRoot;
    RecipeAVL reciRoot;
    TimeAVL prepRoot, cookRoot;
    vector <playList> pl;
    unordered_map<string, int>diffMap;
    unordered_map<string, int>cuiCodeMap;
    PrepBox()
    {

        diffMap["Easy"]=1;
        diffMap["Medium"]=2;
        diffMap["Hard"]=3;
        RecipeFromFile("RecipeList.txt", rcp);
        cuiCodeMap["indian"]=101;
        cuiCodeMap["italian"]=102;
        cuiCodeMap["mexican"]=102;
        cuiCodeMap["chinese"]=103;
        int ul[]={15,30,45,60,75,90,105};
        for(int i=0;i<7;i++)
            {
            prepRoot.insertT(prepRoot.root,ul[i]);
            cookRoot.insertT(cookRoot.root,ul[i]);
            }
            createPlaylist();
    }

//unordered_map<string, pair<double, string>> parseIngredients(const string& ingredients) {
//    unordered_map<string, pair<double, string>> ingredientMap;
//    stringstream ss(ingredients);
//    string item;
//
//    // Split the ingredients list by commas
//    while (getline(ss, item, ',')) {
//        // Split each ingredient by the colon
//        size_t pos = item.find(":");
//        if (pos != string::npos) {
//            string name = item.substr(0, pos);
//            string quantityUnit = item.substr(pos + 1);
//
//            // Trim whitespace (optional, implement a helper function if needed)
//            name.erase(0, name.find_first_not_of(" \t"));
//            name.erase(name.find_last_not_of(" \t") + 1);
//            quantityUnit.erase(0, quantityUnit.find_first_not_of(" \t"));
//            quantityUnit.erase(quantityUnit.find_last_not_of(" \t") + 1);
//
//            // Split the quantity and unit
//            stringstream qtyStream(quantityUnit);
//            double quantity;
//            string unit;
//
//            if (qtyStream >> quantity) {
//                getline(qtyStream, unit); // Read the remaining unit as a string
//                unit.erase(0, unit.find_first_not_of(" \t")); // Trim leading whitespace
//            } else {
//                // Handle special cases like "to taste"
//                quantity = 0.0;
//                unit = quantityUnit;
//            }
//
//            // Insert into the map
//            ingredientMap[name] = make_pair(quantity, unit);
//        }
//    }
//
//    return ingredientMap;
//}
//
//    unordered_map<string, pair<double, string>> ingredientMap = parseIngredients(ingredients);
//
//    // Print the map
//    for (const auto& ingredient : ingredientMap) {
//        cout << ingredient.first << " -> " << ingredient.second.first << " " << ingredient.second.second << endl;
//    }
//
//    return 0;
//}
void RecipeFromFile(string filename, vector<Recipe> &recipeList) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    string line, name, cuisine, category, difficulty, description, instructions, ingredientsStr;
    int prepTime, cookTime;

    try {
        while (getline(file, line)) {
            if (line.rfind("Name: ", 0) == 0)
                name = line.substr(6);
            else if (line.rfind("Cuisine: ", 0) == 0)
                cuisine = line.substr(9);
            else if (line.rfind("Category: ", 0) == 0)
                category = line.substr(10);
            else if (line.rfind("Difficulty: ", 0) == 0)
                difficulty = line.substr(12);
            else if (line.rfind("PrepTime: ", 0) == 0)
                prepTime = stoi(line.substr(10));
            else if (line.rfind("CookTime: ", 0) == 0)
                cookTime = stoi(line.substr(10));
            else if (line.rfind("Ingredients: ", 0) == 0)
                ingredientsStr = line.substr(13);
            else if (line.rfind("Description: ", 0) == 0)
                description = line.substr(13);
            else if (line.rfind("Instructions: ", 0) == 0)
                instructions = line.substr(14);
            else if (line == "---") { // End of a recipe
                unordered_map<string, pair<double, string>> ingredientMap;
    stringstream ss(ingredientsStr);
    string item;

    // Split the ingredients list by commas
    while (getline(ss, item, ',')) {
        // Split each ingredient by the colon
        size_t pos = item.find(":");
        if (pos != string::npos) {
            string name = item.substr(0, pos);
            string quantityUnit = item.substr(pos + 1);

            // Trim whitespace (optional, implement a helper function if needed)
            name.erase(0, name.find_first_not_of(" \t"));
            name.erase(name.find_last_not_of(" \t") + 1);
            quantityUnit.erase(0, quantityUnit.find_first_not_of(" \t"));
            quantityUnit.erase(quantityUnit.find_last_not_of(" \t") + 1);

            // Split the quantity and unit
            stringstream qtyStream(quantityUnit);
            double quantity;
            string unit;

            if (qtyStream >> quantity) {
                getline(qtyStream, unit); // Read the remaining unit as a string
                unit.erase(0, unit.find_first_not_of(" \t")); // Trim leading whitespace
            } else {
                quantity = 0.0;
                unit = quantityUnit;
            }

            ingredientMap[name] = make_pair(quantity, unit);
        }
    }
                int cui=cuiCodeMap[cuisine];
                int diff=diffMap[difficulty];
                // Create and store the recipe
                Recipe r(name, cui, cuisine, diff, prepTime, cookTime, ingredientMap, description, instructions);
                recipeList.push_back(r);
                r.nutritionalValue();

                name = cuisine = category = difficulty = description = instructions = ingredientsStr = "";
                prepTime = cookTime = 0;
            }
        }
    } catch (const exception &e) {
        cerr << "Error reading file: " << filename << ". Exception: " << e.what() << "\n";
    }
    cout<<"Data retrieved"<<endl;
    file.close();
}

void disall()
{
    for(int i=0; i<50; i++)
        rcp[i].detailed_recipe(i);
}
    void sortByPrepTime()
    {
        vector<Recipe> arr; //creating a temporary list of recipes to be displayed
        arr=rcp;
        MergeSortP(arr ,0,arr.size());
        displayCurr(arr);
    }
void ingredient_search()
{

    vector <Recipe> res=rcp;//result set
    vector <Recipe> tempRes(res.size());//temporary result set
    int n=rcp.size();//no. of recipes in the result set
    int m;//no. of recipes in temporary result set
    string ch;//present ingredient to be filtered
    cout<<"\t\t\t*----------INGREDIENTS FILTER----------*"<<endl;//10 '-'
    cout<<"Enter the required ingredient(s), when done press '0'"<<endl;
    cin>>ch;
    while(ch!="0")
    {
        m=0;
        for(int i=0;i<n;i++)
        {
            if(res[i].ingredients.find(ch)!=res[i].ingredients.end())
            {
                tempRes[m++]=res[i];
            }
        }
        tempRes.resize(m);
        res=tempRes;
        n=m;
        cin>>ch;

    }
    cout<<endl;
    cout<<"Filtered Recipes:"<<endl;
    displayCurr(res);
}
    // vector<Recipe> filterByCategory()
    // {

    // }
    void dislikes()
{
    vector<Recipe> res=rcp;//result set
    vector<Recipe> tempRes(res.size());//temporary result set
    int n=res.size();//no. of recipes in the result set
    int nRec,m;//no. of recipes in temporary result set
    string ch;//present ingredient to be filtered out
    cout<<"\t\t\t*----------INGREDIENTS TO BE FILTERED OUT----------*"<<endl;//10 '-'
    cout<<"Enter the ingredient(s) to be filtered out, when done press '0'"<<endl;
    cin>>ch;
    while(ch!="0")
    {
        m=0;
        for(int i=0;i<n;i++)
        {
            if(res[i].ingredients.find(ch)==res[i].ingredients.end())
            {
                tempRes[m++]=res[i];
            }
        }
        tempRes.resize(m);
        res=tempRes;
        n=m;
        cin>>ch;
    }
    cout<<endl;
    cout<<"Filtered Recipes:"<<endl;
    displayCurr(res);
}

    vector<Recipe> sortByDifficulty()
    {
        //frequency
        int freq[3];
        for(int i=0; i<rcp.size(); i++)
            freq[rcp[i].get_difficulty()-1]++;
        //cummulative freq
        for(int i=1; i<3; i++)
            freq[i]+=freq[i-1];

        vector <Recipe> result;
        for(int i=rcp.size()-1; i>=0; i--)
            result[--freq[rcp[i].get_difficulty()-1]]=rcp[i];

        return result;
    }



//    void playDisp(vec)
    vector<Recipe> filterByDifficulty(int d)
    {
        vector<Recipe> filtered;
        int diff;
        for(int i=0; i<rcp.size(); i++)
        {
            diff=rcp[i].get_difficulty();
            if(diff== d)
            filtered.push_back(rcp[i]);
        }
        return filtered;
    }

    void filterByCuisine(int code)
    {
        cuiRoot.find(cuiRoot.root, code)->recipes.inOrder();
    }




//    void createPlaylist(vector <playList> pl)
//    {
//    int i=0,j=0;
//    playList A("Healthy Choices","Discover a collection of delicious, nutritious, and easy-to-make recipes designed to nourish your body and delight your taste buds.\n From wholesome breakfasts to satisfying dinners, this cookbook focuses on fresh, natural ingredients to support a balanced and healthy lifestyle.\n Perfect for anyone looking to make mindful eating a delicious habit!\n");
//    A.rc.push_back(rcp[1]);
//     A.rc.push_back(rcp[1]);
//    }

void sortByCookTime()
    {
        vector <Recipe> arr;
        arr=rcp;
        MergeSortC(arr,0,arr.size());
    }

    void search_by_name(string n)
    {
        int ns;
        RecipeNode* x=reciRoot.find(reciRoot.root,n);
        Recipe R=x->data;
        cout<<"Enter number of servings: "<<endl;
        cin>>ns;
        R.detailed_recipe(ns);
    }

    void createPlaylist()
    {
    playList healthyChoices("Healthy Choices", "Discover a collection of delicious, nutritious, and easy-to-make recipes designed to nourish your body and delight your taste buds.\nFrom wholesome breakfasts to satisfying dinners, this playlist focuses on fresh, natural ingredients to support a balanced and healthy lifestyle.\nPerfect for anyone looking to make mindful eating a delicious habit!");
    playList sweetCravings("Craving Something Sweet", "A playlist of indulgent desserts and sweet treats that satisfy your sugar cravings!\nFrom traditional desserts to unique recipes, explore options that delight every sweet tooth.");
    playList lazyCooking("Feeling Lazy", "For those days when you don’t feel like cooking, this playlist features recipes that are simple, quick, and require minimal effort.");
    playList quickFixes("Quick Fixes", "Short on time? This playlist is your go-to for quick and easy meals that are ready in no time, without compromising on taste!");
    playList crunchyMunchy("Crunchy Munchy", "Perfect for snack lovers, this playlist is filled with recipes that are crispy, crunchy, and irresistible.");

    healthyChoices.rc.push_back(rcp[1]);  // Pasta Primavera
    healthyChoices.rc.push_back(rcp[17]); // Kanda Batata Poha
    healthyChoices.rc.push_back(rcp[18]); // Lemon Rice
    healthyChoices.rc.push_back(rcp[33]); // Stir Fry Tofu
    healthyChoices.rc.push_back(rcp[27]); // Ravioli

    sweetCravings.rc.push_back(rcp[3]);  // Rasgulla
    sweetCravings.rc.push_back(rcp[4]);  // Gulab Jamun
    sweetCravings.rc.push_back(rcp[10]); // Jalebi
    sweetCravings.rc.push_back(rcp[26]); // Tiramisu
    sweetCravings.rc.push_back(rcp[27]); // Churros

    lazyCooking.rc.push_back(rcp[13]); // Aloo Paratha
    lazyCooking.rc.push_back(rcp[19]); // Paneer Paratha
    lazyCooking.rc.push_back(rcp[12]); // Chole Bhature
    lazyCooking.rc.push_back(rcp[22]); // Alfredo Pasta
    lazyCooking.rc.push_back(rcp[34]); // Ramen

    quickFixes.rc.push_back(rcp[2]);  // Masala Dosa
    quickFixes.rc.push_back(rcp[5]);  // Dhokla
    quickFixes.rc.push_back(rcp[8]);  // Garlic Cheese Bread
    quickFixes.rc.push_back(rcp[38]); // Wontons
    quickFixes.rc.push_back(rcp[21]); // Garlic Naan

    crunchyMunchy.rc.push_back(rcp[9]);  // Cantonese Spring Rolls
    crunchyMunchy.rc.push_back(rcp[35]); // Kung Pao Chicken
    crunchyMunchy.rc.push_back(rcp[40]); // Bao Buns
    crunchyMunchy.rc.push_back(rcp[24]); // Lasagna
    crunchyMunchy.rc.push_back(rcp[29]); // Nachos

    pl.push_back(healthyChoices);
    pl.push_back(sweetCravings);
    pl.push_back(lazyCooking);
    pl.push_back(quickFixes);
    pl.push_back(crunchyMunchy);
    for(int i=0;i<pl.size();i++)
    {
        pl[i].pnum=i;
    }
}

};
int main()
{

system("cls");
 const std::string blue = "\033[1;34m";
 const std::string black = "\033[30m";
 const std::string red = "\033[31m";
 const std::string green = "\033[32m";
 const std::string yellow= "\033[33m";
 const std::string magenta = "\033[35m";
 const std::string cyan= "\033[36m";
 const std::string white= "\033[37m";
 cout<<"\033[1m";
 cout <<yellow<< R"(

         .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.       .----------------.  .----------------.
       | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |     | .--------------. || .--------------. |
       | | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |     | |  _________   | || |     ____     | |
       | ||_   ||   || || | |   ___  |  | || |  |_   |     | || |   .' ___  |  | || |   .'    `.   | || ||   \  /   || || | |   ___  |  | |     | | |  _   _  |  | || |   .'    `.   | |
       | |  | | /\ | |  | || |   | |_  \|  | || |    | |       | || |  / .'   \|  | || |  /  .--.  \  | || |  |   \/   |  | || |   | |_  \|  | |     | | |/ | | \_|  | || |  /  .--.  \  | |
       | |  | |/  \| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\  /| |  | || |   |  _|  _   | |     | |     | |      | || |  | |    | |  | |
       | |  |   /\   |  | || |  | |/ |  | || |   | |/ |  | || |  \ `..'\  | || |  \  `--'  /  | || | | |\/| | | || |  | |/ |  | |     | |    | |     | || |  \  `--'  /  | |
       | |  |/  \|  | || | ||  | || |  ||  | || |   `..'  | || |   `..'   | || |||||| || | ||  | |     | |   ||    | || |   `..'   | |
       | |              | || |              | || |              | || |              | || |              | || |              | || |              | |     | |              | || |              | |
       | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |     | '--------------' || '--------------' |
        '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'       '----------------'  '----------------'
                          .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.
                         | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
                         | |   ______     | || |  _______     | || |  _________   | || |   ______     | || |   ______     | || |     ____     | || |  ____  ____  | |
                         | |  |_   __ \   | || | |_   __ \    | || | |_   ___  |  | || |  |_   __ \   | || |  |_   _ \    | || |   .'    `.   | || | |_  ||  _| | |
                         | |    | |) |  | || |   | |) |   | || |   | |_  \|  | || |    | |) |  | || |    | |) |   | || |  /  .--.  \  | || |   \ \  / /   | |
                         | |    |  ___/   | || |   |  __ /    | || |   |  _|  _   | || |    |  ___/   | || |    |  __'.   | || |  | |    | |  | || |    > `' <    | |
                         | |   | |      | || |  | |  \ \  | || |  | |/ |  | || |   | |      | || |   | |_) |  | || |  \  --'  /  | || |  _/ /'\ \_  | |
                         | |  ||     | || | || || | || | ||  | || |  ||     | || |  |/   | || |   `..'   | || | |||_| | |
                         | |              | || |              | || |              | || |              | || |              | || |              | || |              | |
                         | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
                          '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'

     )" <<endl;
 cout<<endl;
 system("pause");
 system("cls");
 cout <<white<<R"(
             Your ultimate destination for achieving food goals with personalized recipe!
 )";
 system("pause");
 cout<<"\033[40m";
 cout<<"\033[30m";
 system("cls");

    PrepBox obj;
    int choice;
    do {
//        system("cls");
        cout << "Main Menu\n";

        cout << "1. Display All Recipe\n";
        cout << "2. Sort Recipes by Cook Time\n";
        cout << "3. Filter Recipes by Cuisine\n";
        cout << "4. Filter Recipes by Prep Time\n";
        cout << "5. Filter Recipes by Cook Time\n";
        cout << "6. Search Recipes by Ingredient\n";
        cout << "7. Check Disliked Ingredients\n";
        cout << "8. Display Premade Playlist\n";
        cout << "9. Detailed Recipe\n";
        cout << "10. Exit\n";
        cout << "";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            obj.disall();
            obj.sortByPrepTime();
            break;
            case 2:
            obj.sortByCookTime();
            break;
            case 3:
            {
                int cc;
                cout<<"Enter cuisine code: ";
                cin>>cc;
                obj.filterByCuisine(cc);
            break;
            }
case 4:
            {
                int ul,ll;
                cout<<"The time ranges are: "<<endl;
                cout<<"1: 0, 15 mins"<<endl;
                cout<<"2: 15, 30 mins"<<endl;
                cout<<"3: 30, 45 mins"<<endl;
                cout<<"4: 45, 60 mins"<<endl;
                cout<<"5: 60, 75 mins"<<endl;
                cout<<"6: 75, 90 mins"<<endl;
                cout<<"7: 90, 105 mins"<<endl;
                cout<<"Enter which time range to be displayed: "<<endl;
                cout<<"Enter upper limit: "<<endl;
                cin>>ul;
                cout<<"Enter lower limit: "<<endl;
                cin>>ll;
                obj.prepRoot.displayRange(ll,ul);
            }
            break;
            case 5:
            int ul,ll;
                cout<<"The time ranges are: "<<endl;
                cout<<"1: 0, 15 mins"<<endl;
                cout<<"2: 15, 30 mins"<<endl;
                cout<<"3: 30, 45 mins"<<endl;
                cout<<"4: 45, 60 mins"<<endl;
                cout<<"5: 60, 75 mins"<<endl;
                cout<<"6: 75, 90 mins"<<endl;
                cout<<"7: 90, 105 mins"<<endl;
                cout<<"Enter which time range to be displayed: "<<endl;
                cout<<"Enter upper limit: "<<endl;
                cin>>ul;
                cout<<"Enter lower limit: "<<endl;
                cin>>ll;
                obj.cookRoot.displayRange(ll,ul);

            break;
            case 6:
            obj.ingredient_search();
            break;
            case 7:
            obj.dislikes();
            break;
            case 8:
            {
                int p;
                cout<<"Playlists are: "<<endl;
                for(int i=0;i<obj.pl.size();i++)
                {
                    obj.pl[i].dispPlay();
                }
                cout<<"Enter which playlist should be displayed: "<<endl;
                cin>>p;
                for(int i=0;i<obj.pl[p].rc.size();i++)
                {
                    obj.pl[p].rc[i].displaySRecipe();
                }
            }
            break;

                case 9:
                    string na;
                    cout<<"Enter Name";
                    cin>>na;
                obj.reciRoot.displayRecipe(na);
                break;
        }int ri,n;

        cout<<"Enter recipe index of the recipe you want to view in detail: "<<endl;
        cin>>ri;
        cout<<"Enter number of people you want to serve: "<<endl;
        cin>>n;
        obj.rcp[ri].detailed_recipe(n);
        cout << "\nDo you want to:\n";
        cout << "1. Go back to the Main Menu\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        int nextChoice;
        cin >> nextChoice;
        if (nextChoice == 2) {
            cout << "Exiting...\n";
            return 0; // Exit from the program
        }
        system("cls");
    } while (true);
}
