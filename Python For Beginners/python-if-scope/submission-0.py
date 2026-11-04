def pay_bill(balance: int, bill: int) -> int:
    new_balance=balance-bill
    if balance >= bill:
      return new_balance
    else:
      return balance



# do not modify below this line
print(pay_bill(100, 50))
print(pay_bill(100, 100))
print(pay_bill(100, 150))
