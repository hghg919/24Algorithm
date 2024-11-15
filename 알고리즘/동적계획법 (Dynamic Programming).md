# 동적계획법

## 정의  
- 복잡한 문제를 간단한 여러 개의 문제로 나누어 푼다. (Problem - SubProblem)
- 같은 문제를 여러번 반복해서 풀어야 하는 경우가 발생한다.
- 반복된 여러 개의 문제를 최적화된 방식으로 해를 구하는 알고리즘.

## 핵심
- 중복된 사항을 파악하고, 중복을 없애는 방법

## 어떻게 반복을 줄일 것인가?

- Top - Down 방식 (memoization)

- Botton - up 방식 (tabulation)

## 예시
- 피보나치 수열 
- 배낭 문제
- 계단 오르기 문제 

## 메모이제이션

- memo : 내용을 적어놓고, 필요할 때 사용하기 위해서 필기
- 재귀적인 방식으로 구현하여, 조금 더 이해하기 쉽다.

## 메모이제이션 방식과 타뷸레이션 방식의 차이점

### 메모이제이션 방식
- Top-Down 방식으로 큰 문제에서 작은 문제를 해결해 나가는 방식입니다.
- 중복되는 문제를 해결하기 위해, 각 문제를 처음 해결할 때만 계산을 수행하고, 이후에는 미리 저장된 값을 사용합니다. (Memoization)
- 작은 문제 중의 일부만 필요해도 전체 답을 구할 수 있을 때 더 효율적이다.

### 타뷸레이션 방식
- Bottom-Up 방식으로 작은 문제들을 해결해서 큰 문제들을 차례대로 해결해 나가는 방식입니다.
- 재귀 호출 없이 반복문을 통해 목표값까지 차례대로 해결해나갑니다.
- 작은 문제들의 모든 해(Solution)이 곧 답에 필요한 경우에 적합하다.

## 정리
- 두 방식 모두 효율적으로 동적 계획법 문제를 해결할 수 있는 방법입니다. 메모이제이션 방식은 재귀 호출과 함께 문제를 풀기 때문에
조금 더 직관적으로 문제 식을 작성할 수 있습니다.
- 타뷸레이션 방식은 재귀 호출을 사용하지 않기 때문에 함수 호출에 의한 오버헤드가 적게 발생합니다, 조금더 메모리 효율적이라고 할 수 있습니다.
