class NestedInteger {

 *   public:

 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.

 *     bool isInteger() const;

 *

 *     // Return the single integer that this NestedInteger holds, if it holds a single integer

 *     // The result is undefined if this NestedInteger holds a nested list

 *     int getInteger() const;

 *

 *     // Return the nested list that this NestedInteger holds, if it holds a nested list

 *     // The result is undefined if this NestedInteger holds a single integer

 *     const vector<NestedInteger> &getList() const;

 * };

 */

class NestedIterator {

public:

    void dfsHelper(vector<NestedInteger>& nestedList)

    {

        for (int i = 0; i < nestedList.size(); i++)

        {

            if (nestedList[i].isInteger()) {

                nums.emplace(nestedList[i].getInteger());

            } else dfsHelper(nestedList[i].getList());

        }

    }

    NestedIterator(vector<NestedInteger> &nestedList) {

        dfsHelper(nestedList);

    }



    int next() {

        int num = nums.front();

        nums.pop();

        return num;

    }



    bool hasNext() {

        return !nums.empty();

    }

private:

    queue<int> nums;

};
