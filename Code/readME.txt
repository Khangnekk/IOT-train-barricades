Trong code có 2 file

// File Arduino1.c là code của chip truyền (Arduino có các mạch kết nối với cảm biến siêu âm)

Code này sẽ có nhiệm vụ thu thập dữ liệu từ các cảm biến siêu âm
nếu cảm biến siêu âm gặp vật cản sẽ trả về giá trị true, ngược lại trả về false

Khi truyền dữ liệu đi nó sẽ truyền 6 biến boolean sang Arduino 2 thông qua UART 

// File Arduino2.c là code của chip nhận (Arduino có các mạch kết nối với các thành phần còn lại)

Code này sẽ nhận các dữ liệu được gửi đi từ Arduino 1 và xử lý nó