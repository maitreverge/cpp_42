# /bin/sh

echo ""
echo "\e[1;31mBefore script\e[0m"
echo "----------"
echo ""
ls -la

# reset all authorizations
chmod 000 *.txt

# READ + WRITE to koala
chmod 664 koala.txt

# Only READ rights
chmod +r NO_WRITE_RIGHTS.txt

# Only WRITE
chmod +w NO_READ_RIGHTS.txt


echo ""
echo "\e[1;32mAfter script\e[0m"
echo "----------"
echo ""
ls -la