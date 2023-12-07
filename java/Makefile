compile:
	javac -d . *.java
	jar cfve MergeSort.jar MergeSort MergeSort.class
	rm -rf *.class

clean:
	rm -rf *.class
	rm -rf *.jar

run:
	java -jar MergeSort.jar

compile-run: compile run