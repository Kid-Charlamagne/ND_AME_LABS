
voltages = 3:1:12;
voltages = [3 8 12];

N = length(voltages);

Data = {};

for vol = voltages
    answer = questdlg('Hold the motor farmly! Then press the OK button.', ...
            'Safety Warning!!!', ...
            'Continue','Cancle','Continue');
        if isequal(answer,'Cancle')
            error('Cancled');
        end
    
    outputData = ApplyVoltage(vol);
    Data{end+1} = outputData;
    close all
    
end
%% 

data.vol = [];
data.cut = [];
finished = 0;

%% 

for i = finished+1:N
    disp(i);
    outputData = Data{i};
    current = outputData(:,2);
    time = outputData(:,1);
    plot(time,current)
    grid on
    while true
        timeStart = inputdlg({'The start time for the data'},'Input');
        timeEnd   = inputdlg({'The end time for the data'},'Input');
        if isempty(timeStart) || isempty(timeEnd)
            error("No time");
        end
        timeStart = str2double(timeStart{1});
        timeEnd   = str2double(timeEnd{1});
        [~,index_start] = min(abs(time - timeStart));
        [~,index_end]   = min(abs(time - timeEnd  ));
        xregion_general(time(index_start),time(index_end));
        data.vol(end+1) = voltages(i);
        data.cut(end+1) = mean(current(index_start:index_end));
        
        answer = questdlg('Pick Another Region?', ...
            'Pick Data', ...
            'Yes','No','Yes');
        if isequal(answer, 'No')
            break;
        end
    end
    finished = i;
    close all
end

%% 

close all
scatter(data.vol(:),data.cut(:));
hold on
grid on
xlim([0,12])
ylim([0,3])

B = data.vol(:)\data.cut(:);
R = 1/B;

voltages = 0:1:12;
plot(voltages,B*voltages);


