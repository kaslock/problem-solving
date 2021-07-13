class Solution {
    
    int numbers_size = 0;
    int target_number = 0;
    int answer = 0;
    
    public void subset(int[] numbers, int depth, int cur) {
        if (depth >= numbers_size) {
            if (cur == target_number) answer++;
            return;    
        }
        
        subset(numbers, depth + 1, cur + numbers[depth]);
        subset(numbers, depth + 1, cur - numbers[depth]);
    }
    
    public int solution(int[] numbers, int target) {
        numbers_size = numbers.length;
        target_number = target;
        
        subset(numbers, 0, 0);
        
        return answer;
    }
}