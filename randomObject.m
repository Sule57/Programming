%Matrix size
n = 1000;

%Filling the matrix with 0's (matrix main character)
neo = zeros(1000,1000);

%iterations
it = 100000;

% Random variables between 1 and n
p1 = randi(n, 1, 2);
p2 = randi(n, 1, 2);
p3 = randi(n, 1, 2);

%starting point
start = p1;

for i = 0:it
    %putting the start point in the matrix
    neo(start(1), start(2)) = true;
    %random number 1-3
    rand = randi(3, 1, 1);
    
    %what we get defines our new dot
    if rand == 1
        
        start = fix((start + p1) / 2);
    
    elseif rand == 2

        start = fix((start + p2) / 2);
    
    else

        start = fix((start + p3) / 2);
    end
end
%Getting the image
spy(neo, "r.")


