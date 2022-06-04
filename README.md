1. Hướng dẫn cài đặt:
* Cài đặt Codeblock:
  + Vào đường dẫn: https://www.fosshub.com/Code-Blocks.html?dwl=codeblocks-20.03mingw-setup.exe, file sẽ tự động tải
  + Vào tệp lưu file vừa tải, khởi chạy file codeblocks-20.03mingw-setup.exe
  + Bấm Next
  ![image](https://user-images.githubusercontent.com/82645696/172009018-b37c48d3-c145-4833-af39-3beaab40614e.png)
  + Bấm I Agree
  ![image](https://user-images.githubusercontent.com/82645696/172009232-af38dddb-ae50-4c04-a6d3-cc93d59639f9.png)
  + Bấm Next
  ![image](https://user-images.githubusercontent.com/82645696/172009347-60e7fe6a-243e-49b5-954b-9f0f3aa8d6b3.png)
  + Bấm Browse, chọn vị trí lưu file ( nếu muốn )
  + Bấm Install
  ![image](https://user-images.githubusercontent.com/82645696/172009459-f8f16439-f872-41d3-b4b9-9c6d0020cfec.png)
  + Bấm Yes để mở Codeblock luôn hoặc bạn có thể mở sau bằng icon ![image](https://user-images.githubusercontent.com/82645696/172010277-2af8938c-be05-48c5-9ace-87c98841367c.png)
  ![image](https://user-images.githubusercontent.com/82645696/172010267-2a4227a7-71d1-4738-a6a4-0f588f8e9c20.png)
* Cài đặt game
  + Vào đường link https://github.com/huytd1012/Sokoban
  ![image](https://user-images.githubusercontent.com/82645696/172010415-f153f135-695e-4141-baeb-f27aac18a30c.png)
  + Bấm nút Code
  ![image](https://user-images.githubusercontent.com/82645696/172010477-7044f0bf-5440-46f0-9dc3-aad78ea12a19.png)
  + Bấm Download ZIP
  ![image](https://user-images.githubusercontent.com/82645696/172010864-f23445ca-c447-4b53-a34b-02a1d5b9e098.png)
  + Giải nén file zip
  + Mở tệp Sokoban-main\sokoban
  + Bấm chuột phải chọn mở file sokuban.cbp bằng Code::Block IDE
  + Bấm f9 là chạy được
2. Mô tả: Trò chơi đẩy thùng cổ điển:
  - Mục tiêu : đẩy hết các thùng vào ô có chấm xanh
  - Cách chơi: sử dụng phím mũi tên để di chuyển
  - Các ý tưởng chính:
    + Có thể quay lại bước đi trước 
    + Có thể chơi lại 
    + Có âm thanh khi di chuyển và bấm nút
    + Sau khi chơi xong có thể chơi tiếp ván tiếp theo hoặc quay lại ván trước
    + Có thể tạm dừng, quay lại menu, chơi tiếp sau khi quay lại menu
3. Các chức năng đã cài đặt:
+ Sử dụng phím mũi tên để di chuyển
+ Có thể quay lại các bước đi trước bằng nút![image](https://user-images.githubusercontent.com/82645696/172011272-c3d925a1-dd92-4cf4-9f5f-299930f0584d.png)
+ Có thể chơi lại bằng nút ![image](https://user-images.githubusercontent.com/82645696/172011354-0f676fbf-77f3-488a-997c-ae202b882144.png)bằng nút ![image](https://user-images.githubusercontent.com/82645696/172011354-0f676fbf-77f3-488a-997c-ae202b882144.png)
+ Sau khi xong một màn có thể sang màn kế tiếp hoặc quay lại màn trước đó
+ Có thể tạm dừng, quay lại menu, chơi tiếp sau khi quay lại menu
+ Có thể tắt bật âm thanh bằng nút![image](https://user-images.githubusercontent.com/82645696/172011442-e8e421df-2853-45c8-ad5f-86100ca897a2.png)
+ link youtube minh họa: https://youtu.be/NRklWnEjYYQ
4. Các kỹ thuật được sử dụng:
+ Mảng
+ Cấu trúc
+ Con trỏ
+ Đồ họa SDL, SDL_image
+ Âm thanh SDL_mixer
+ Bắt chuyển động của chuột, bàn phím
5.
+ Kết luận: 
  - Game đã hoàn thiện về mặt hình ảnh
  - Còn chưa quá mượt
  - Ít màn, chưa có chọn màn
  - Âm thanh chỉ mới phát qua loa ngoài
+ Hướng phát triển: 
  - Vẽ game mượt hơn
  - Thêm màn, thêm chức năng chọn màn
  - Người chơi có thể chọn đầu ra âm thanh
+ Điều tâm đắc: Trò chơi đã có hình ảnh, âm thanh, chạy ổn định

*NOTE : tham khảo map từ trang https://www.cbc.ca/kids/games/play/sokoban và hình ảnh lấy từ trang https://opengameart.org/content/sokoban-100-tiles
