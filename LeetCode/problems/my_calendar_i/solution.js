var MyCalendar = function() 
{
  this.events = [[0,0],[Infinity, Infinity]]
};

MyCalendar.prototype.book = function(start, end) 
{
   const events = this.events
  
  if (events.length === 2) {
    events.splice(1, 0, [start, end])
    return true
  }

  for (let i = events.length - 1; i >= 0; i--) {
    if (events[i][1] <= start && events[i+1][0] >= end) {
      events.splice(i+1, 0, [start, end])
      return true
    }
  }

  return false 
};