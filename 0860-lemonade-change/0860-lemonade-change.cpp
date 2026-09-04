class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(auto money:bills){
            if(money==5){
                five++;
            }
            if(money==10){
                ten++;
            }
            int toreturn=money-5;
            if(toreturn==0) continue;
            if(toreturn >10){
                if(ten){
                    ten--;
                    toreturn-=10;
                }
            }
                if(five*5<toreturn){
                    //its mean whatever coin we have of five we cant change fullfill the return account

                    return false;
                }
                else{
                    five-=(toreturn/5);
                }
            
        }

        return true;

    }
};